#include <unordered_map>
#include <main/php_network.h>
#include "app.h"

std::unordered_map<zend_long, wxEventLoopSource*> wxEventLoopSources;
std::unordered_map<zend_long, wxEventLoopSource*> wxEventLoopReadSources;
std::unordered_map<zend_long, wxEventLoopSource*> wxEventLoopWriteSources;

class wxPhpEventLoopSourceHandler: public wxEventLoopSourceHandler
{
    public:
        wxPhpEventLoopSourceHandler(zval *fd)
        {
            stream = (php_stream *) zend_fetch_resource_ex(fd, NULL, php_file_le_stream());
        }

        void OnReadWaiting()
        {
            Dispatch(wxEVENT_SOURCE_INPUT);
        }

        void OnWriteWaiting()
        {
            Dispatch(wxEVENT_SOURCE_OUTPUT);
        }

        void OnExceptionWaiting()
        {
            Dispatch(wxEVENT_SOURCE_EXCEPTION);
        }

    protected:
        void Dispatch(long flags)
        {
            wxAppWrapper* instance = (wxAppWrapper*) wxApp::GetInstance();

            if (instance == NULL)
            {
                return;
            }

            zval retval;
            zval arg[2];

            ZVAL_LONG(&arg[0], flags);
            ZVAL_RES(&arg[1], stream->res);

            instance->FireCallback(&retval, arg, 2, WXPHP_FD_EVENT_CB);

            zval_ptr_dtor(&retval);
            zval_ptr_dtor(&arg[0]);
        }

        php_stream *stream;
};

class wxPhpEventLoopSourceReadHandler: public wxPhpEventLoopSourceHandler
{
    using wxPhpEventLoopSourceHandler::wxPhpEventLoopSourceHandler;

    void OnWriteWaiting()
    {
        zend_error(E_CORE_ERROR, "wxPhpEventLoopSourceReadHandler: Cannot handle write events for read handlers");
    }
};

class wxPhpEventLoopSourceWriteHandler: public wxPhpEventLoopSourceHandler
{
    using wxPhpEventLoopSourceHandler::wxPhpEventLoopSourceHandler;

    void OnReadWaiting()
    {
        zend_error(E_CORE_ERROR, "wxPhpEventLoopSourceWriteHandler: Cannot handle write events for read handlers");
    }
};

/* {{{ proto wxEventLoopSource wxEventLoopBase::AddSourceForFD(stream res, int flags)
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

    zval* res;
    long flags;

    char parse_parameters_string[] = "zl";
    if (!zend_parse_parameters_ex(
        ZEND_PARSE_PARAMS_QUIET,
        arguments_received,
        parse_parameters_string,
        &res,
        &flags
    ) == SUCCESS) {
        zend_error(
            E_ERROR,
            "wxEventLoopBase::AddSourceForFD incorrect arguments"
        );

        return;
    }

    php_stream *stream;
    php_socket_t fd = -1;

    if (Z_TYPE_P(res) == IS_RESOURCE) {
        if ((stream = (php_stream *) zend_fetch_resource_ex(res, NULL, php_file_le_stream()))) {
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
        RETURN_NULL();
    }

    wxPhpEventLoopSourceHandler* wxEvLoopSrcHandler;

    flags |= wxEVENT_SOURCE_EXCEPTION;

    if (flags == wxEVENT_SOURCE_ALL) {
        wxEvLoopSrcHandler = new wxPhpEventLoopSourceHandler(res);
    } else if (flags & wxEVENT_SOURCE_INPUT) {
        wxEvLoopSrcHandler = new wxPhpEventLoopSourceReadHandler(res);
    } else if (flags & wxEVENT_SOURCE_OUTPUT) {
        wxEvLoopSrcHandler = new wxPhpEventLoopSourceWriteHandler(res);
    }

    if (!wxEvLoopSrcHandler) {
        zend_error(E_ERROR, "Could not create event loop source handler");
        RETURN_NULL();
    }

    wxEventLoopSource *wxEventLoopSrc = (((wxEventLoopBase_php*)native_object)->AddSourceForFD(fd, wxEvLoopSrcHandler, flags));

    if (!wxEventLoopSrc) {
        delete wxEvLoopSrcHandler;
        zend_error(E_ERROR, "Could not create event loop source handler");
        RETURN_NULL();
    }

    zend_long streamId = php_stream_get_resource_id(stream);

    if (flags == wxEVENT_SOURCE_ALL) {
        wxEventLoopSources[streamId] = wxEventLoopSrc;
    } else if (flags & wxEVENT_SOURCE_INPUT) {
        wxEventLoopReadSources[streamId] = wxEventLoopSrc;
    } else if (flags & wxEVENT_SOURCE_OUTPUT) {
        wxEventLoopWriteSources[streamId] = wxEventLoopSrc;
    }

    RETURN_LONG(streamId);
}
