/* {{{ proto bool wxEventLoopBase::RemoveSourceForFD(int fd)
   wxEventLoopBase::RemoveSourceForFD */
PHP_METHOD(php_wxEventLoopBase, RemoveSourceForFD)
{
    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking wxEventLoopBase::RemoveSourceForFD\n");
    php_printf("===========================================\n");
    #endif

    zo_wxEventLoopBase* current_object;
    wxphp_object_type current_object_type;
    wxEventLoopBase_php* native_object;
    void* argument_native_object = NULL;

    //Other variables used thru the code
    zval dummy;
    ZVAL_NULL(&dummy);
    bool already_called = false;
    wxPHPObjectReferences* references;
    int arguments_received = ZEND_NUM_ARGS();
    bool return_is_user_initialized = false;

    //Get native object of the php object that called the method
    if(getThis() != NULL)
    {
        current_object = Z_wxEventLoopBase_P(getThis());

        if(current_object->native_object == NULL)
        {
            zend_error(
                E_ERROR,
                "Failed to get the native object for "
                "wxEventLoopBase::RemoveSourceForFD call\n"
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
    }
    #ifdef USE_WXPHP_DEBUG
    else
    {
        php_printf("Processing the method call as static\n");
    }
    #endif

    //Parameters for overload 0
    long fd0;
    long flags;
    bool overload0_called = false;

    //Overload 0
    overload0:
    if(!already_called && arguments_received == 2)
    {
        #ifdef USE_WXPHP_DEBUG
        php_printf("Parameters received %d\n", arguments_received);
        php_printf("Parsing parameters with 'l' (&fd0)\n");
        #endif

        char parse_parameters_string[] = "ll";
        if(zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, arguments_received, parse_parameters_string, &fd0, &flags ) == SUCCESS)
        {
            overload0_called = true;
            already_called = true;
        }
    }

    if(overload0_called)
    {
        switch(arguments_received)
        {
            case 2:
            {
                #ifdef USE_WXPHP_DEBUG
                php_printf("Executing RETURN_BOOL(wxEventLoopBase::RemoveSourceForFD((long) fd0))\n\n");
                #endif

                if(current_object_type == PHP_WXEVENTLOOPBASE_TYPE)
                {
                    wxEventLoopSource *wxEventLoopSrc = NULL;
                    flags |= wxEVENT_SOURCE_EXCEPTION;

                    if (flags == wxEVENT_SOURCE_ALL) {
                        wxEventLoopSrc = wxEventLoopSources[fd0];

                        if (wxEventLoopSrc) {
                            wxEventLoopSources.erase(fd0);
                        }
                    } else if (flags & wxEVENT_SOURCE_INPUT) {
                        wxEventLoopSrc = wxEventLoopReadSources[fd0];

                        if (wxEventLoopSrc) {
                            wxEventLoopReadSources.erase(fd0);
                        }
                    } else if (flags & wxEVENT_SOURCE_OUTPUT) {
                        wxEventLoopSrc = wxEventLoopWriteSources[fd0];

                        if (wxEventLoopSrc) {
                            wxEventLoopWriteSources.erase(fd0);
                        }
                    }

                    if (!wxEventLoopSrc) {
                        RETURN_FALSE;
                    }

                    wxPhpEventLoopSourceHandler *handler = dynamic_cast<wxPhpEventLoopSourceHandler *>(wxEventLoopSrc->GetHandler());

                    delete handler;
                    delete wxEventLoopSrc;

                    RETURN_TRUE;
                }

                RETURN_FALSE;
                break;
            }
        }
    }

    //In case wrong type/count of parameters was passed
    if(!already_called)
    {
        zend_error(
            E_ERROR,
            "Wrong type or count of parameters passed to: "
            "wxEventLoopBase::RemoveSourceForFD\n"
        );
    }
}
/* }}} */
