/*
 * @author Mário Soares
 * @contributors Jefferson González
 * @contributors René Vögeli / Rangee GmbH
 * @contributors Ciprian Dosoftei
 *
 * @license
 * This file is part of wxPHP check the LICENSE file for information.
 *
 * @description
 * Manual binding implemetation of the wxApp class
 *
*/

#include "php_wxwidgets.h"
#include "app.h"
#include "appmanagement.h"

/**
 * Set the wxWidgets application handler.
 */
wxIMPLEMENT_APP_NO_MAIN(wxAppWrapper);

BEGIN_EXTERN_C()
zend_object* php_wxApp_new(zend_class_entry *class_type)
{
    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Calling php_wxApp_new on %s at line %i\n",
        zend_get_executed_filename(),
        zend_get_executed_lineno()
    );
    php_printf("===========================================\n");
    #endif

    zo_wxApp* custom_object;

    custom_object = (zo_wxApp*) ecalloc(
        1,
        sizeof(zo_wxApp)
        + zend_object_properties_size(class_type)
    );

    zend_object_std_init(&custom_object->zo, class_type);
    object_properties_init(&custom_object->zo, class_type);

    memcpy(&wxphp_wxApp_object_handlers, zend_get_std_object_handlers(), sizeof wxphp_wxApp_object_handlers);
    wxphp_wxApp_object_handlers.offset = XtOffsetOf(zo_wxApp, zo);
    wxphp_wxApp_object_handlers.free_obj = php_wxApp_free;
    custom_object->zo.handlers = &wxphp_wxApp_object_handlers;

    custom_object->native_object = NULL;
    custom_object->object_type = PHP_WXAPP_TYPE;
    custom_object->is_user_initialized = 0;

    return &custom_object->zo;
}

void php_wxApp_free(zend_object *object)
{
    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Calling php_wxApp_free on %s at line %i\n",
        zend_get_executed_filename(),
        zend_get_executed_lineno()
    );
    php_printf("===========================================\n");
    #endif

    zo_wxApp* custom_object = php_wxApp_fetch_object(object);
    zend_object_std_dtor(&custom_object->zo);
}
END_EXTERN_C()

bool wxAppWrapper::OnInit()
{
    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::OnInit\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "OnInit", 6);

    zval function_return_value;

    int function_called;

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s' on wxApp\n",
        Z_STRVAL(function_name)
    );
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
                NULL, &phpObj, &function_name, &function_return_value,
                0, NULL
        );

        if (EG(exception)) {
            zend_error(E_CORE_ERROR, "Uncaught exception in wxApp::OnInit");
            return false;
        }

        if(function_called == SUCCESS)
        {
            return true;
        }

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed. Calling native method instead.\n");
        #endif
    }

    return wxApp::OnInit();
}

void wxAppWrapper::OnEventLoopEnter(wxEventLoopBase *loop)
{
    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::OnEventLoopEnter\n");
    php_printf("===========================================\n");
    #endif

    if (!loop) {
        return;
    }

    zval retval;
    zend_string *function_name = zend_string_init("OnEventLoopEnter", strlen("OnEventLoopEnter"), 0);

    int function_called;

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s' on wxApp\n",
        Z_STRVAL(function_name)
    );
    #endif

    if (is_php_user_space_implemented) {
        zval params[1];
        wxEventLoopBase_php* phpObjLoop = (wxEventLoopBase_php *)loop;

        object_init_ex(&params[0], php_wxEventLoopBase_entry);
        Z_wxEventLoopBase_P(&params[0])->native_object = (wxEventLoopBase_php*) phpObjLoop;

        function_called = zend_call_method_if_exists(Z_OBJ(phpObj), function_name, &retval, 1, params);
        zend_string_release(function_name);
        zval_ptr_dtor(&retval);

        if (function_called != SUCCESS) {
            zval_ptr_dtor(&params[0]);
            return;
        }

        if (EG(exception)) {
            zend_error(E_CORE_ERROR, "Uncaught exception in wxApp::OnEventLoopEnter");
            zval_ptr_dtor(&params[0]);
            return;
        }

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed. Calling native method instead.\n");
        #endif
    }
}

int wxAppWrapper::OnExit()
{
    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::OnExit\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "OnExit", 6);

    zval function_return_value;

    int function_called;

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s' on wxApp\n",
        Z_STRVAL(function_name)
    );
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            0, NULL
        );

        if (EG(exception)) {
            zend_error(E_CORE_ERROR, "Uncaught exception in wxApp::OnExit");
            return false;
        }

        if(function_called == SUCCESS)
        {
            return true;
        }

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed. Calling native method instead.\n");
        #endif
    }

    return wxApp::OnExit();
}

void wxAppWrapper::SetCallback(zend_fcall_info *fci, zend_fcall_info_cache *fcc, enum wxphp_callback_type type)
{
    wxphp_cb_t *cb;

    if (wxphp_callbacks[type] == NULL) {
        cb = (wxphp_cb_t *) emalloc(sizeof(wxphp_cb_t));
    } else {
        cb = wxphp_callbacks[type];

        if (Z_TYPE(cb->fci.function_name) != IS_UNDEF) {
            zval_dtor(&cb->fci.function_name);
        }

        if (cb->fci.object) {
            GC_DELREF(cb->fci.object);
        }
    }

    memcpy(&cb->fci, fci, sizeof(zend_fcall_info));
    memcpy(&cb->fcc, fcc, sizeof(zend_fcall_info_cache));

    if (ZEND_FCI_INITIALIZED(cb->fci)) {
        Z_TRY_ADDREF(cb->fci.function_name);

        if (cb->fci.object) {
            GC_ADDREF(cb->fci.object);
        }
    }

    wxphp_callbacks[type] = cb;
}

int wxAppWrapper::FireCallback(zval *retval_ptr, zval *params, int param_count, enum wxphp_callback_type type)
{
    int error = 0;

    if (ZEND_FCI_INITIALIZED(wxphp_callbacks[type]->fci)) {
        wxphp_callbacks[type]->fci.params = params;
        wxphp_callbacks[type]->fci.retval = retval_ptr;
        wxphp_callbacks[type]->fci.param_count = param_count;

        if (zend_call_function(&wxphp_callbacks[type]->fci, &wxphp_callbacks[type]->fcc) != SUCCESS) {
            error = -1;
        }
    } else {
        error = -2;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Unhandled exception in wxAppWrapper::FireCallback");
    }

    return error;
}

#ifdef __WXMAC__
void wxAppWrapper::MacNewFile()
{
    static bool is_php_user_space_implemented = true;

    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::MacNewFile\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "MacNewFile", 10);

    zval function_return_value;

    int function_called;

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s'",
        Z_STRVAL(function_name)
    );

    if (phpObj->value.obj->ce == NULL) {
        php_printf(" on NULL!\n");
    } else {
        php_printf(" on '%s'\n", ZSTR_VAL(phpObj->value.obj->ce->name));
    }
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            0, NULL
        );
    }
    else
    {
        function_called = FAILURE;
    }

    if(function_called == FAILURE)
    {
        is_php_user_space_implemented = false;

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed\n");
        #endif
    }
}

void wxAppWrapper::MacOpenFiles ( const wxArrayString &  fileNames)
{
    static bool is_php_user_space_implemented = true;

    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::MacOpenFiles\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "MacOpenFiles", 12);

    zval* params[1];
    zval arguments[1];

    zval function_return_value;

    int function_called;

    //Parameters for conversion
    array_init(&arguments[0]);
    for(int i=0; i<fileNames.GetCount(); i++)
    {
        add_next_index_string(
            &arguments[0],
            fileNames[i].ToUTF8().data()
        );
    }

    //Set parameters that are sent to function
    params[0] = &arguments[0];

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s'",
        Z_STRVAL(function_name)
    );

    if (phpObj->value.obj->ce == NULL) {
        php_printf(" on NULL!\n");
    } else {
        php_printf(" on '%s'\n", ZSTR_VAL(phpObj->value.obj->ce->name));
    }
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            1, *params
        );
    }
    else
    {
        function_called = FAILURE;
    }

    //Delete already used parameters from memory
    zval_ptr_dtor(&arguments[0]);

    if(function_called == FAILURE)
    {
        is_php_user_space_implemented = false;

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed\n");
        #endif
    }
}

void wxAppWrapper::MacOpenFile(const wxString& fileName)
{
    static bool is_php_user_space_implemented = true;

    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::MacOpenFile\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "MacOpenFile", 11);

    zval* params[1];
    zval arguments[1];

    zval function_return_value;

    int function_called;

    //Parameters for conversion
    ZVAL_STRING(&arguments[0], fileName.ToUTF8().data());

    //Set parameters that are sent to function
    params[0] = &arguments[0];

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s'",
        Z_STRVAL(function_name)
    );

    if (phpObj->value.obj->ce == NULL) {
        php_printf(" on NULL!\n");
    } else {
        php_printf(" on '%s'\n", ZSTR_VAL(phpObj->value.obj->ce->name));
    }
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            1, *params
        );
    }
    else
    {
        function_called = FAILURE;
    }

    //Delete already used parameters from memory
    zval_ptr_dtor(&arguments[0]);

    if(function_called == FAILURE)
    {
        is_php_user_space_implemented = false;

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed\n");
        #endif
    }
}

void wxAppWrapper::MacOpenURL(const wxString& url)
{
    static bool is_php_user_space_implemented = true;

    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::MacOpenURL\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "MacOpenURL", 10);

    zval* params[1];
    zval arguments[1];

    zval function_return_value;

    int function_called;

    //Parameters for conversion
    ZVAL_STRING(&arguments[0], url.ToUTF8().data());

    //Set parameters that are sent to function
    params[0] = &arguments[0];

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s'",
        Z_STRVAL(function_name)
    );

    if (phpObj->value.obj->ce == NULL) {
        php_printf(" on NULL!\n");
    } else {
        php_printf(" on '%s'\n", ZSTR_VAL(phpObj->value.obj->ce->name));
    }
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            1, *params
        );
    }
    else
    {
        function_called = FAILURE;
    }

    //Delete already used parameters from memory
    zval_ptr_dtor(&arguments[0]);

    if(function_called == FAILURE)
    {
        is_php_user_space_implemented = false;

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed\n");
        #endif
    }
}

void wxAppWrapper::MacPrintFile(const wxString& fileName)
{
    static bool is_php_user_space_implemented = true;

    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::MacPrintFile\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "MacPrintFile", 12);

    zval* params[1];
    zval arguments[1];

    zval function_return_value;

    int function_called;

    //Parameters for conversion
    ZVAL_STRING(&arguments[0], fileName.ToUTF8().data());

    //Set parameters that are sent to function
    params[0] = &arguments[0];

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s'",
        Z_STRVAL(function_name)
    );

    if (phpObj->value.obj->ce == NULL) {
        php_printf(" on NULL!\n");
    } else {
        php_printf(" on '%s'\n", ZSTR_VAL(phpObj->value.obj->ce->name));
    }
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            1, *params
        );
    }
    else
    {
        function_called = FAILURE;
    }

    //Delete already used parameters from memory
    zval_ptr_dtor(&arguments[0]);

    if(function_called == FAILURE)
    {
        is_php_user_space_implemented = false;

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed\n");
        #endif
    }
}

void wxAppWrapper::MacReopenApp()
{
    static bool is_php_user_space_implemented = true;

    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::MacReopenApp\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "MacReopenApp", 12);

    zval function_return_value;

    int function_called;

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s'",
        Z_STRVAL(function_name)
    );

    if (phpObj->value.obj->ce == NULL) {
        php_printf(" on NULL!\n");
    } else {
        php_printf(" on '%s'\n", ZSTR_VAL(phpObj->value.obj->ce->name));
    }
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            0, NULL
        );
    }
    else
    {
        function_called = FAILURE;
    }

    if(function_called == FAILURE)
    {
        is_php_user_space_implemented = false;

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed\n");
        #endif
    }
}

bool wxAppWrapper::OSXIsGUIApplication()
{
    static bool is_php_user_space_implemented = true;

    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking virtual wxApp::OSXIsGUIApplication\n");
    php_printf("===========================================\n");
    #endif

    zval function_name;
    ZVAL_STRINGL(&function_name, "OSXIsGUIApplication", 19);

    zval function_return_value;

    int function_called;

    #ifdef USE_WXPHP_DEBUG
    php_printf(
        "Trying to call user defined method '%s'",
        Z_STRVAL(function_name)
    );

    if (phpObj->value.obj->ce == NULL) {
        php_printf(" on NULL!\n");
    } else {
        php_printf(" on '%s'\n", ZSTR_VAL(phpObj->value.obj->ce->name));
    }
    #endif

    if(is_php_user_space_implemented)
    {
        function_called = call_user_function(
            NULL, &phpObj, &function_name, &function_return_value,
            0, NULL
        );
    }
    else
    {
        function_called = FAILURE;
    }

    if(function_called == FAILURE)
    {
        is_php_user_space_implemented = false;

        #ifdef USE_WXPHP_DEBUG
        php_printf("Invocation of user defined method failed\n");
        #endif

        return true;
    }

    #ifdef USE_WXPHP_DEBUG
    php_printf("Returning userspace value.\n");
    #endif

    return Z_TYPE(function_return_value) == IS_TRUE;
}
#endif

wxAppWrapper::~wxAppWrapper()
{
    for (size_t i = 0; i < WXPHP_CB_MAX; i++) {
        if (wxphp_callbacks[i] != NULL) {
            if (ZEND_FCI_INITIALIZED(wxphp_callbacks[i]->fci)) {
                zval_dtor(&wxphp_callbacks[i]->fci.function_name);

                if (wxphp_callbacks[i]->fci.object) {
                    OBJ_RELEASE(wxphp_callbacks[i]->fci.object);
                }
            }

            efree(wxphp_callbacks[i]);
            wxphp_callbacks[i] = NULL;
        }
    }
}

/* {{{ proto wxApp wxApp::__construct()
   Constructor. */
PHP_METHOD(php_wxApp, __construct)
{
    zo_wxApp* current_object;

    wxAppWrapper* native_object = new wxAppWrapper();
    native_object->phpObj = *getThis();
    native_object->is_php_user_space_implemented = true;

    current_object = Z_wxApp_P(getThis());

    current_object->native_object = native_object;

    current_object->is_user_initialized = 1;
}
/* }}} */

/* {{{ proto void wxApp::SetInstance(wxApp app)
   Allows external code to modify global wxTheApp, but you should
   really know what you're doing if you call it.*/
PHP_METHOD(php_wxApp, SetInstance)
{
    zval *objvar;

    if(
        zend_parse_parameters(
            ZEND_NUM_ARGS(), (char *)"O", &objvar, php_wxApp_entry
        )
        ==
        FAILURE
    )
    {
        RETURN_NULL();
    }

    GC_ADDREF(Z_OBJ_P(objvar));

    // To-do: decrease the reference count for the former wxApp, if any

    wxApp::SetInstance(Z_wxApp_P(objvar)->native_object);
}
/* }}} */

/* {{{ proto void wxApp::GetInstance() */
PHP_METHOD(php_wxApp, GetInstance)
{
    wxAppWrapper* instance = (wxAppWrapper*) wxApp::GetInstance();

    if(instance == NULL)
    {
        RETURN_NULL();
    }
    else if(!Z_ISNULL(instance->phpObj)) // Todo: Does this work?
    {
        ZVAL_COPY_VALUE(return_value, &instance->phpObj);
        zval_add_ref(&instance->phpObj);
    }
    else
    {
        object_init_ex(return_value, php_wxApp_entry);
        Z_wxApp_P(return_value)->native_object = instance;
    }
}
/* }}} */

/* {{{ proto bool wxApp::Yield() */
PHP_METHOD(php_wxApp, Yield)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    if (zend_parse_parameters_none() == FAILURE)
        return;

    RETURN_BOOL(native_object->Yield());
}
/* }}} */

/* {{{ proto bool wxApp::GetAppDisplayName() */
PHP_METHOD(php_wxApp, GetAppDisplayName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    wxString value_to_return = native_object->GetAppDisplayName();

    RETURN_STRING(value_to_return.ToUTF8().data());
}
/* }}} */

/* {{{ proto bool wxApp::GetAppName() */
PHP_METHOD(php_wxApp, GetAppName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    wxString value_to_return = native_object->GetAppName();

    RETURN_STRING(value_to_return.ToUTF8().data());
}
/* }}} */

/* {{{ proto bool wxApp::GetClassName() */
PHP_METHOD(php_wxApp, GetClassName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    wxString value_to_return = native_object->GetClassName();

    RETURN_STRING(value_to_return.ToUTF8().data());
}
/* }}} */

/* {{{ proto bool wxApp::GetVendorDisplayName() */
PHP_METHOD(php_wxApp, GetVendorDisplayName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    wxString value_to_return = native_object->GetVendorDisplayName();

    RETURN_STRING(value_to_return.ToUTF8().data());
}
/* }}} */

/* {{{ proto bool wxApp::GetVendorName() */
PHP_METHOD(php_wxApp, GetVendorName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    wxString value_to_return = native_object->GetVendorName();

    RETURN_STRING(value_to_return.ToUTF8().data());
}
/* }}} */


/* {{{ proto bool wxApp::SetAppDisplayName(string name) */
PHP_METHOD(php_wxApp, SetAppDisplayName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    char* name;
    size_t name_len;

    if(ZEND_NUM_ARGS() > 0)
    {
        char parse_parameters_string[] = "s";

        if(
            zend_parse_parameters_ex(
                ZEND_PARSE_PARAMS_QUIET,
                ZEND_NUM_ARGS(),
                parse_parameters_string,
                &name,
                &name_len
            ) == SUCCESS
        )
        {
            native_object->SetAppDisplayName(
                wxString(name, wxConvUTF8)
            );
        }
    }
}
/* }}} */

/* {{{ proto bool wxApp::SetAppName(string name) */
PHP_METHOD(php_wxApp, SetAppName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    char* name;
    size_t name_len;

    if(ZEND_NUM_ARGS() > 0)
    {
        char parse_parameters_string[] = "s";

        if(
            zend_parse_parameters_ex(
                ZEND_PARSE_PARAMS_QUIET,
                ZEND_NUM_ARGS(),
                parse_parameters_string,
                &name,
                &name_len
            ) == SUCCESS
        )
        {
            native_object->SetAppName(
                wxString(name, wxConvUTF8)
            );
        }
    }
}
/* }}} */

/* {{{ proto bool wxApp::SetClassName(string name) */
PHP_METHOD(php_wxApp, SetClassName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    char* name;
    size_t name_len;

    if(ZEND_NUM_ARGS() > 0)
    {
        char parse_parameters_string[] = "s";

        if(
            zend_parse_parameters_ex(
                ZEND_PARSE_PARAMS_QUIET,
                ZEND_NUM_ARGS(),
                parse_parameters_string,
                &name,
                &name_len
            ) == SUCCESS
        )
        {
            native_object->SetClassName(
                wxString(name, wxConvUTF8)
            );
        }
    }
}
/* }}} */

/* {{{ proto bool wxApp::SetVendorDisplayName(string name) */
PHP_METHOD(php_wxApp, SetVendorDisplayName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    char* name;
    size_t name_len;

    if(ZEND_NUM_ARGS() > 0)
    {
        char parse_parameters_string[] = "s";

        if(
            zend_parse_parameters_ex(
                ZEND_PARSE_PARAMS_QUIET,
                ZEND_NUM_ARGS(),
                parse_parameters_string,
                &name,
                &name_len
            ) == SUCCESS
        )
        {
            native_object->SetVendorDisplayName(
                wxString(name, wxConvUTF8)
            );
        }
    }
}
/* }}} */

/* {{{ proto bool wxApp::SetVendorName(string name) */
PHP_METHOD(php_wxApp, SetVendorName)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;

    char* name;
    size_t name_len;

    if(ZEND_NUM_ARGS() > 0)
    {
        char parse_parameters_string[] = "s";

        if(
            zend_parse_parameters_ex(
                ZEND_PARSE_PARAMS_QUIET,
                ZEND_NUM_ARGS(),
                parse_parameters_string,
                &name,
                &name_len
            ) == SUCCESS
        )
        {
            native_object->SetVendorName(
                wxString(name, wxConvUTF8)
            );
        }
    }
}
/* }}} */

/* {{{ proto void wxApp::SetCallback(callable fn, long type) */
PHP_METHOD(php_wxApp, SetCallback)
{
    wxAppWrapper* native_object = Z_wxApp_P(getThis())->native_object;
    zend_fcall_info fci = empty_fcall_info;
    zend_fcall_info_cache fcc = empty_fcall_info_cache;
    zend_long type;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_FUNC_EX(fci, fcc, 1, 0)
        Z_PARAM_LONG(type)
    ZEND_PARSE_PARAMETERS_END();

    native_object->SetCallback(&fci, &fcc, WXPHP_FD_EVENT_CB);
}
/* }}} */
