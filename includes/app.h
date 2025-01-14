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
 * Manual binding declaration to the wxApp class
 *
*/

#ifndef WXPHP_APP_H_GUARD
#define WXPHP_APP_H_GUARD

#include "object_types.h"

extern zend_class_entry *php_wxApp_entry;
extern zend_object_handlers wxphp_wxApp_object_handlers;

class wxAppWrapper : public wxApp
{
    public:
        bool OnInit();
        void OnEventLoopEnter(wxEventLoopBase *loop);
        int OnExit();

        void SetCallback(zend_fcall_info *fci, zend_fcall_info_cache *fcc, enum wxphp_callback_type type);
        int FireCallback(zval *retval_ptr, zval *params, int param_count, enum wxphp_callback_type type);

        #ifdef __WXMAC__
        void MacNewFile();
        void MacOpenFiles(const wxArrayString&  fileNames);
        void MacOpenFile(const wxString& fileName);
        void MacOpenURL(const wxString& url);
        void MacPrintFile(const wxString& fileName);
        void MacReopenApp();
        bool OSXIsGUIApplication();
        #endif

        bool is_php_user_space_implemented = false;
        zval phpObj;

        ~wxAppWrapper();

    protected:
        wxphp_cb_t *wxphp_callbacks[WXPHP_CB_MAX] = { NULL };
};

BEGIN_EXTERN_C()
typedef struct _zo_wxApp
{
    wxAppWrapper* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxApp;

void php_wxApp_free(zend_object *object);
zend_object* php_wxApp_new(zend_class_entry *class_type);
END_EXTERN_C()

ZEND_BEGIN_ARG_INFO_EX(arginfo_php_wxApp_SetInstance, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(1, app, wxApp, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_php_wxApp_SetCallback, 0, 0, 2)
    ZEND_ARG_CALLABLE_INFO(1, fn, 0)
    ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

static zend_function_entry php_wxApp_functions[] = {
    PHP_ME(php_wxApp, SetInstance, arginfo_php_wxApp_SetInstance, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, GetInstance, arginfo_null, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, GetAppDisplayName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, GetAppName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, GetClassName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, GetVendorDisplayName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, GetVendorName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, SetAppDisplayName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, SetAppName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, SetClassName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, SetVendorDisplayName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, SetVendorName, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, SetCallback, arginfo_php_wxApp_SetCallback, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, Yield, arginfo_null, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxApp, __construct, arginfo_null, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    { NULL, NULL, NULL }
};

static inline zo_wxApp * php_wxApp_fetch_object(zend_object *obj) {
    return (zo_wxApp *)((char *)(obj) - XtOffsetOf(zo_wxApp, zo));
}

#define Z_wxApp_P(zv) php_wxApp_fetch_object(Z_OBJ_P(zv))

#endif //WXPHP_APP_H_GUARD
