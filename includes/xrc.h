/*
 * @author Mário Soares
 * @contributors Jefferson González
 * @contributors René Vögeli / Rangee GmbH
 * 
 * @license 
 * This file is part of wxPHP check the LICENSE file for information.
 * 
 * @note
 * This file was auto-generated by the wxPHP source maker
*/

#ifndef WXPHP_XRC_H_GUARD
#define WXPHP_XRC_H_GUARD

#include "references.h"
#include "object_types.h"

ZEND_BEGIN_ARG_INFO_EX(wxphp_xrc_get_args, 0, 0, 1)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

extern zend_class_entry* php_wxXmlResourceHandler_entry;
extern zend_object_handlers wxphp_wxXmlResourceHandler_object_handlers;
void php_wxXmlResourceHandler_destruction_handler(zend_resource*);

class wxXmlResourceHandler_php: public wxXmlResourceHandler{
    public:

    wxXmlResourceHandler_php():wxXmlResourceHandler(){}
    
    bool CanHandle(wxXmlNode* node);
    wxObject* DoCreateResource();
    

    ~wxXmlResourceHandler_php();

    struct _zo_wxXmlResourceHandler *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxXmlResourceHandler{
    wxXmlResourceHandler_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxXmlResourceHandler;

void php_wxXmlResourceHandler_free(zend_object *object);
zend_object* php_wxXmlResourceHandler_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxXmlResourceHandler_functions[] = {
    PHP_ME(php_wxXmlResourceHandler, CreateResource, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResourceHandler, SetParentResource, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResourceHandler, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_FE_END
};
#endif


static inline zo_wxXmlResourceHandler * php_wxXmlResourceHandler_fetch_object(zend_object *obj) {
    return (zo_wxXmlResourceHandler *)(
        (char *)(obj) - XtOffsetOf(zo_wxXmlResourceHandler, zo)
    );
}

#define Z_wxXmlResourceHandler_P(zv) \
    php_wxXmlResourceHandler_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxXmlResource_entry;
extern zend_object_handlers wxphp_wxXmlResource_object_handlers;
void php_wxXmlResource_destruction_handler(zend_resource*);

class wxXmlResource_php: public wxXmlResource{
    public:

    wxXmlResource_php(const wxString& filemask, int flags=wxXRC_USE_LOCALE, const wxString& domain=wxEmptyString):wxXmlResource(filemask, flags, domain){}
    wxXmlResource_php(int flags=wxXRC_USE_LOCALE, const wxString& domain=wxEmptyString):wxXmlResource(flags, domain){}
    
    void DoReportError(const wxString& xrcFile, const wxXmlNode* position, const wxString& message);
    

    ~wxXmlResource_php();

    struct _zo_wxXmlResource *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxXmlResource{
    wxXmlResource_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxXmlResource;

void php_wxXmlResource_free(zend_object *object);
zend_object* php_wxXmlResource_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxXmlResource_functions[] = {
    PHP_ME(php_wxXmlResource, AddHandler, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, AttachUnknownControl, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, ClearHandlers, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, CompareVersion, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, FindXRCIDById, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, Get, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, GetDomain, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, GetFlags, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, GetResourceNode, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, GetVersion, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, GetXRCID, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, InitAllHandlers, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, Load, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadAllFiles, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadDialog, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadFile, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadFrame, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadIcon, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadMenu, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadMenuBar, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadObject, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadObjectRecursively, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadPanel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, LoadToolBar, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, Set, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, SetDomain, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, SetFlags, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, Unload, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxXmlResource, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_FE_END
};
#endif


static inline zo_wxXmlResource * php_wxXmlResource_fetch_object(zend_object *obj) {
    return (zo_wxXmlResource *)(
        (char *)(obj) - XtOffsetOf(zo_wxXmlResource, zo)
    );
}

#define Z_wxXmlResource_P(zv) \
    php_wxXmlResource_fetch_object(Z_OBJ_P(zv))
#endif //WXPHP_XRC_H_GUARD
