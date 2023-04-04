#include <main/php_network.h>

// To do: there is no lifecycle management for the source handler (nor the event loop sources!)
//        i.e. they're not being cleaned up when the monitored stream is removed.

class wxPhpEventLoopSourceHandler: public wxEventLoopSourceHandler
{
    public:
        wxPhpEventLoopSourceHandler(zval *fd, zend_fcall_info *fci, zend_fcall_info_cache *fci_cache)
        {
            stream = (php_stream *) zend_fetch_resource_ex(fd, NULL, php_file_le_stream());

            memcpy(&this->fd, fd, sizeof(zval));
            memcpy(&this->fci, fci, sizeof(zend_fcall_info));
            memcpy(&this->fci_cache, fci_cache, sizeof(zend_fcall_info_cache));

            this->ce = fci_cache->calling_scope;
            this->func_ptr = fci_cache->function_handler;
            this->obj = fci_cache->object;

            if (this->obj) {
                GC_ADDREF(this->obj);
            }

            if (Z_TYPE(fci->function_name) == IS_OBJECT) {
                this->closure = Z_OBJ(fci->function_name);
                GC_ADDREF(this->closure);
            } else {
                this->closure = NULL;
            }
        }

        void OnReadWaiting()
        {
            //php_stream *stream = (php_stream *) zend_fetch_resource_ex(&fd, NULL, php_file_le_stream());

            // To do: we shouldn't have to do this with proper object lifecycle management
            if (!stream) {
                return;
            }

            zend_long streamId = php_stream_get_resource_id(stream);
            php_printf("OnReadWaiting(%d)\n", streamId);

            Dispatch(wxEVENT_SOURCE_INPUT);
        }

        void OnWriteWaiting()
        {
            //php_stream *stream = (php_stream *) zend_fetch_resource_ex(&fd, NULL, php_file_le_stream());

            // To do: we shouldn't have to do this with proper object lifecycle management
            if (!stream) {
                return;
            }

            zend_long streamId = php_stream_get_resource_id(stream);
            php_printf("OnWriteWaiting(%d)\n", streamId);

            Dispatch(wxEVENT_SOURCE_OUTPUT);
        }

        void OnExceptionWaiting()
        {
            //php_stream *stream = (php_stream *) zend_fetch_resource_ex(&fd, NULL, php_file_le_stream());

            // To do: we shouldn't have to do this with proper object lifecycle management
            if (!stream) {
                return;
            }

            zend_long streamId = php_stream_get_resource_id(stream);
            php_printf("OnExceptionWaiting(%d)\n", streamId);

            Dispatch(wxEVENT_SOURCE_EXCEPTION);
        }

        ~wxPhpEventLoopSourceHandler()
        {
            php_printf("wxPhpEventLoopSourceHandler DESTROYER(%d)\n");

            if (this->obj) {
                zend_object_release(this->obj);
            }

            if (this->func_ptr &&
                UNEXPECTED(this->func_ptr->common.fn_flags & ZEND_ACC_CALL_VIA_TRAMPOLINE)) {
                zend_string_release_ex(this->func_ptr->common.function_name, 0);
                zend_free_trampoline(this->func_ptr);
            }

            if (this->closure) {
                zend_object_release(this->closure);
            }
        }

    protected:
        void Dispatch(long flags)
        {
            zval dummy;
            zval arg[2];

            ZVAL_LONG(&arg[0], flags);
            ZVAL_RES(&arg[1], stream->res);
            // memcpy(&arg[1], &fd, sizeof(zval));

            fci.retval = &dummy;
            fci.param_count = 2;
            fci.params = arg;

            #if PHP_VERSION_ID < 80000
            fci.no_separation = 0;
            #endif

            #if PHP_VERSION_ID >= 80000
            fci.named_params = NULL;
            #endif

            zend_result res = zend_call_function(&fci, &fci_cache);
            zval_ptr_dtor(&dummy);
            zval_ptr_dtor(&arg[0]);

            if (res == FAILURE) {
                zend_error(E_CORE_WARNING, "Cannot call wxPhpEventLoopSourceHandler::Dispatch");
            } else if (EG(exception)) {
                zend_error(E_CORE_ERROR, "Exception thrown in wxPhpEventLoopSourceHandler::Dispatch");
            }
        }

        php_stream *stream;

        zval fd;
        zend_fcall_info fci;
        zend_fcall_info_cache fci_cache;
        zend_function *func_ptr;
        zend_object *obj;
        zend_object *closure;
        zend_class_entry *ce;
};


/* {{{ proto wxEventLoopSource wxEventLoopBase::AddSourceForFD(int fd, int flags)
   wxEventLoopBase::AddSourceForFD */
PHP_METHOD(php_wxEventLoopBase, AddSourceForFD)
{
    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking wxEventLoopBase::AddSourceForFD\n");
    php_printf("===========================================\n");
    #endif

    zo_wxEventLoopBase* current_object;
    wxphp_object_type current_object_type;
    wxEventLoopBase_php* native_object;
    void* argument_native_object = NULL;

    zval dummy;
    ZVAL_NULL(&dummy);
    bool already_called = false;
    wxPHPObjectReferences* references;
    int arguments_received = ZEND_NUM_ARGS();
    bool return_is_user_initialized = false;

    if(getThis() != NULL)
    {
        current_object = Z_wxEventLoopBase_P(getThis());

        if(current_object->native_object == NULL)
        {
            zend_error(
                E_ERROR,
                "Failed to get the native object for "
                "wxEventLoopBase::AddSourceForFD call\n"
            );

            return;
        }
        else
        {
            native_object = current_object->native_object;
            current_object_type = current_object->object_type;

            bool reference_type_found = false;

            if(current_object_type == PHP_WXEVENTLOOPBASE_TYPE){
                references = &((wxEventLoopBase_php*)native_object)->references;
                reference_type_found = true;
            }
        }
    } else {
        zend_error(
            E_ERROR,
            "wxEventLoopBase::AddSourceForFD is not a static method"
        );

        return;
    }

    zval* fd0;
    long flags0;
    zend_fcall_info fci = empty_fcall_info;
    zend_fcall_info_cache fci_cache = empty_fcall_info_cache;

    char parse_parameters_string[] = "zlf";
    if (!zend_parse_parameters_ex(
        ZEND_PARSE_PARAMS_QUIET,
        arguments_received,
        parse_parameters_string,
        &fd0,
        &flags0,
        &fci,
        &fci_cache
    ) == SUCCESS) {
        zend_error(
            E_ERROR,
            "wxEventLoopBase::AddSourceForFD incorrect arguments"
        );

        return;
    }

    php_stream *stream;
    php_socket_t fd = -1;

    if (Z_TYPE_P(fd0) == IS_RESOURCE) {
        if ((stream = (php_stream *) zend_fetch_resource_ex(fd0, NULL, php_file_le_stream()))) {
            if (php_stream_cast(stream, PHP_STREAM_AS_FD | PHP_STREAM_CAST_INTERNAL, (void **) &fd, 1) != SUCCESS || fd < 0) {
                fd = -1;
            }
        }
    }

    if (fd == -1) {
        zend_error(
            E_ERROR,
            "wxEventLoopBase::AddSourceForFD cannot retrieve file handle for provided stream"
        );

        return;
    }

    wxPhpEventLoopSourceHandler* wxEvLoopSrcHandler = new wxPhpEventLoopSourceHandler(fd0, &fci, &fci_cache);

    wxEventLoopSource_php* retval;
    if (current_object_type == PHP_WXEVENTLOOPBASE_TYPE) {
        retval = (wxEventLoopSource_php*) ((wxEventLoopBase_php*)native_object)->AddSourceForFD((int) fd, wxEvLoopSrcHandler, (int) flags0);
    }

    if (retval == NULL) {
        RETVAL_NULL();
    } else if(retval->references.IsUserInitialized()) {
        if (!Z_ISNULL(retval->phpObj)) {
            ZVAL_COPY_VALUE(return_value, &retval->phpObj);
            zval_add_ref(&retval->phpObj);
            return_is_user_initialized = true;
        } else {
            zend_error(E_ERROR, "Could not retreive original zval.");
        }
    } else {
        object_init_ex(return_value, php_wxEventLoopSource_entry);
        Z_wxEventLoopSource_P(return_value)->native_object = (wxEventLoopSource_php*) retval;
        Z_wxEventLoopSource_P(return_value)->is_user_initialized = true;
    }

    if (Z_TYPE_P(return_value) != IS_NULL && (void*)retval != (void*)native_object && return_is_user_initialized) {
        references->AddReference(return_value, "wxEventLoopBase::AddSourceForFD at call 5 with 3 argument(s)");
    }
}
