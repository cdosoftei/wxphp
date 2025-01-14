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

#ifndef WXPHP_AUI_H_GUARD
#define WXPHP_AUI_H_GUARD

#include "references.h"
#include "object_types.h"

ZEND_BEGIN_ARG_INFO_EX(wxphp_aui_get_args, 0, 0, 1)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

extern zend_class_entry* php_wxAuiToolBarItem_entry;
extern zend_object_handlers wxphp_wxAuiToolBarItem_object_handlers;
void php_wxAuiToolBarItem_destruction_handler(zend_resource*);

class wxAuiToolBarItem_php: public wxAuiToolBarItem{
    public:

    wxAuiToolBarItem_php():wxAuiToolBarItem(){}
    wxAuiToolBarItem_php(const wxAuiToolBarItem& c):wxAuiToolBarItem(c){}
    
    

    ~wxAuiToolBarItem_php();

    struct _zo_wxAuiToolBarItem *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiToolBarItem{
    wxAuiToolBarItem_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiToolBarItem;

void php_wxAuiToolBarItem_free(zend_object *object);
zend_object* php_wxAuiToolBarItem_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiToolBarItem_functions[] = {
    PHP_ME(php_wxAuiToolBarItem, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxAuiToolBarItem, SetWindow, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetUserData, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetSticky, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetState, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetSpacerPixels, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetSizerItem, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetShortHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetProportion, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetMinSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetLongHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetLabel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetKind, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetId, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetHoverBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetHasDropDown, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetDisabledBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetAlignment, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, SetActive, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, IsSticky, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, IsActive, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, HasDropDown, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetWindow, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetUserData, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetState, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetSpacerPixels, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetSizerItem, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetShortHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetProportion, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetMinSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetLongHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetLabel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetKind, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetId, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetHoverBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetDisabledBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, GetAlignment, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBarItem, Assign, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxAuiToolBarItem * php_wxAuiToolBarItem_fetch_object(zend_object *obj) {
    return (zo_wxAuiToolBarItem *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiToolBarItem, zo)
    );
}

#define Z_wxAuiToolBarItem_P(zv) \
    php_wxAuiToolBarItem_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxAuiToolBarArt_entry;
extern zend_object_handlers wxphp_wxAuiToolBarArt_object_handlers;
void php_wxAuiToolBarArt_destruction_handler(zend_resource*);

class wxAuiToolBarArt_php: public wxAuiToolBarArt{
    public:

    
    wxAuiToolBarArt* Clone();
    void DrawBackground(wxDC& dc, wxWindow* wnd, const wxRect& rect);
    void DrawButton(wxDC& dc, wxWindow* wnd, const wxAuiToolBarItem& item, const wxRect& rect);
    void DrawControlLabel(wxDC& dc, wxWindow* wnd, const wxAuiToolBarItem& item, const wxRect& rect);
    void DrawDropDownButton(wxDC& dc, wxWindow* wnd, const wxAuiToolBarItem& item, const wxRect& rect);
    void DrawGripper(wxDC& dc, wxWindow* wnd, const wxRect& rect);
    void DrawLabel(wxDC& dc, wxWindow* wnd, const wxAuiToolBarItem& item, const wxRect& rect);
    void DrawOverflowButton(wxDC& dc, wxWindow* wnd, const wxRect& rect, int state);
    void DrawSeparator(wxDC& dc, wxWindow* wnd, const wxRect& rect);
    int GetElementSize(int element_id);
    unsigned int GetFlags();
    wxFont GetFont();
    wxSize GetLabelSize(wxDC& dc, wxWindow* wnd, const wxAuiToolBarItem& item);
    int GetTextOrientation();
    wxSize GetToolSize(wxDC& dc, wxWindow* wnd, const wxAuiToolBarItem& item);
    void SetElementSize(int element_id, int size);
    void SetFlags(unsigned int flags);
    void SetFont(const wxFont& font);
    void SetTextOrientation(int orientation);
    

    ~wxAuiToolBarArt_php();

    struct _zo_wxAuiToolBarArt *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiToolBarArt{
    wxAuiToolBarArt_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiToolBarArt;

void php_wxAuiToolBarArt_free(zend_object *object);
zend_object* php_wxAuiToolBarArt_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiToolBarArt_functions[] = {
    PHP_FE_END
};
#endif


static inline zo_wxAuiToolBarArt * php_wxAuiToolBarArt_fetch_object(zend_object *obj) {
    return (zo_wxAuiToolBarArt *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiToolBarArt, zo)
    );
}

#define Z_wxAuiToolBarArt_P(zv) \
    php_wxAuiToolBarArt_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxAuiDefaultToolBarArt_entry;
extern zend_object_handlers wxphp_wxAuiDefaultToolBarArt_object_handlers;
void php_wxAuiDefaultToolBarArt_destruction_handler(zend_resource*);

class wxAuiDefaultToolBarArt_php: public wxAuiDefaultToolBarArt{
    public:

    wxAuiDefaultToolBarArt_php():wxAuiDefaultToolBarArt(){}
    
    

    ~wxAuiDefaultToolBarArt_php();

    struct _zo_wxAuiDefaultToolBarArt *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiDefaultToolBarArt{
    wxAuiDefaultToolBarArt_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiDefaultToolBarArt;

void php_wxAuiDefaultToolBarArt_free(zend_object *object);
zend_object* php_wxAuiDefaultToolBarArt_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiDefaultToolBarArt_functions[] = {
    PHP_ME(php_wxAuiDefaultToolBarArt, CloneMethod, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawBackground, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawControlLabel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawDropDownButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawGripper, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawLabel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawOverflowButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, DrawSeparator, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, GetElementSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, GetFlags, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, GetFont, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, GetLabelSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, GetTextOrientation, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, GetToolSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, SetElementSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, SetFlags, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, SetFont, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, SetTextOrientation, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiDefaultToolBarArt, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_FE_END
};
#endif


static inline zo_wxAuiDefaultToolBarArt * php_wxAuiDefaultToolBarArt_fetch_object(zend_object *obj) {
    return (zo_wxAuiDefaultToolBarArt *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiDefaultToolBarArt, zo)
    );
}

#define Z_wxAuiDefaultToolBarArt_P(zv) \
    php_wxAuiDefaultToolBarArt_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxAuiToolBar_entry;
extern zend_object_handlers wxphp_wxAuiToolBar_object_handlers;
void php_wxAuiToolBar_destruction_handler(zend_resource*);

class wxAuiToolBar_php: public wxAuiToolBar{
    public:

    wxAuiToolBar_php():wxAuiToolBar(){}
    wxAuiToolBar_php(wxWindow* parent, wxWindowID id=wxID_ANY, const wxPoint& position=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxAUI_TB_DEFAULT_STYLE):wxAuiToolBar(parent, id, position, size, style){}
    
    

    ~wxAuiToolBar_php();

    struct _zo_wxAuiToolBar *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiToolBar{
    wxAuiToolBar_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiToolBar;

void php_wxAuiToolBar_free(zend_object *object);
zend_object* php_wxAuiToolBar_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiToolBar_functions[] = {
    PHP_ME(php_wxAuiToolBar, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxAuiToolBar, AddControl, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, AddLabel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, AddSeparator, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, AddSpacer, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, AddStretchSpacer, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, Clear, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, ClearTools, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, DeleteByIndex, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, DeleteTool, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, EnableTool, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, ToggleTool, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetWindowStyleFlag, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolTextOrientation, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolSticky, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolShortHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolSeparation, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolProportion, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolPacking, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolLongHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolLabel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolDropDown, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolBorderPadding, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolBitmapSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetToolBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetOverflowVisible, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetMargins, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetGripperVisible, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, SetFont, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, Realize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, IsPaneValid, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetWindowStyleFlag, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolToggled, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolTextOrientation, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolSticky, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolShortHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolSeparation, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, FindControl, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, FindTool, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, FindToolByIndex, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, FindToolByPosition, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetArtProvider, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetGripperVisible, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetHintSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetOverflowVisible, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolBarFits, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolBitmapSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolBorderPadding, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolCount, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolDropDown, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolEnabled, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolFits, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolFitsByIndex, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolIndex, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolLabel, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolLongHelp, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolPacking, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolPos, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolProportion, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, GetToolRect, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiToolBar, AddTool, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxAuiToolBar * php_wxAuiToolBar_fetch_object(zend_object *obj) {
    return (zo_wxAuiToolBar *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiToolBar, zo)
    );
}

#define Z_wxAuiToolBar_P(zv) \
    php_wxAuiToolBar_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxAuiNotebook_entry;
extern zend_object_handlers wxphp_wxAuiNotebook_object_handlers;
void php_wxAuiNotebook_destruction_handler(zend_resource*);

class wxAuiNotebook_php: public wxAuiNotebook{
    public:

    wxAuiNotebook_php():wxAuiNotebook(){}
    wxAuiNotebook_php(wxWindow* parent, wxWindowID id=wxID_ANY, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxAUI_NB_DEFAULT_STYLE):wxAuiNotebook(parent, id, pos, size, style){}
    
    

    ~wxAuiNotebook_php();

    struct _zo_wxAuiNotebook *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiNotebook{
    wxAuiNotebook_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiNotebook;

void php_wxAuiNotebook_free(zend_object *object);
zend_object* php_wxAuiNotebook_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiNotebook_functions[] = {
    PHP_ME(php_wxAuiNotebook, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxAuiNotebook, Split, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, ShowWindowMenu, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetUniformBitmapSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetTabCtrlHeight, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetSelectedFont, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetPageText, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetPageImage, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetPageBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetNormalFont, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetMeasuringFont, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetFont, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetArtProvider, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, RemovePage, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetTabCtrlHeight, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetSelection, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetPageText, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetPageIndex, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetPageCount, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetPageBitmap, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetPage, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetHeightForPageHeight, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetCurrentPage, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, GetArtProvider, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, DeletePage, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, DeleteAllPages, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, Create, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, ChangeSelection, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, AdvanceSelection, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, AddPage, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiNotebook, SetSelection, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxAuiNotebook * php_wxAuiNotebook_fetch_object(zend_object *obj) {
    return (zo_wxAuiNotebook *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiNotebook, zo)
    );
}

#define Z_wxAuiNotebook_P(zv) \
    php_wxAuiNotebook_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxAuiTabArt_entry;
extern zend_object_handlers wxphp_wxAuiTabArt_object_handlers;
void php_wxAuiTabArt_destruction_handler(zend_resource*);

class wxAuiTabArt_php: public wxAuiTabArt{
    public:

    
    void SetSizingInfo(const wxSize& tab_ctrl_size, size_t tab_count, wxWindow* wnd=NULL);
    void SetSelectedFont(const wxFont& font);
    void SetNormalFont(const wxFont& font);
    void SetMeasuringFont(const wxFont& font);
    void SetFlags(unsigned int flags);
    void SetColour(const wxColour& colour);
    void SetActiveColour(const wxColour& colour);
    wxSize GetTabSize(wxDC& dc, wxWindow* wnd, const wxString& caption, const wxBitmapBundle& bitmap, bool active, int close_button_state, int* x_extent);
    int GetIndentSize();
    void DrawButton(wxDC& dc, wxWindow* wnd, const wxRect& in_rect, int bitmap_id, int button_state, int orientation, wxRect* out_rect);
    void DrawBackground(wxDC& dc, wxWindow* wnd, const wxRect& rect);
    wxAuiTabArt* Clone();
    

    ~wxAuiTabArt_php();

    struct _zo_wxAuiTabArt *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiTabArt{
    wxAuiTabArt_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiTabArt;

void php_wxAuiTabArt_free(zend_object *object);
zend_object* php_wxAuiTabArt_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiTabArt_functions[] = {
    PHP_FE_END
};
#endif


static inline zo_wxAuiTabArt * php_wxAuiTabArt_fetch_object(zend_object *obj) {
    return (zo_wxAuiTabArt *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiTabArt, zo)
    );
}

#define Z_wxAuiTabArt_P(zv) \
    php_wxAuiTabArt_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxAuiManager_entry;
extern zend_object_handlers wxphp_wxAuiManager_object_handlers;
void php_wxAuiManager_destruction_handler(zend_resource*);

class wxAuiManager_php: public wxAuiManager{
    public:

    wxAuiManager_php(wxWindow* managed_wnd=NULL, unsigned int flags=wxAUI_MGR_DEFAULT):wxAuiManager(managed_wnd, flags){}
    
    bool ProcessDockResult(wxAuiPaneInfo& target, const wxAuiPaneInfo& new_pos);
    

    ~wxAuiManager_php();

    struct _zo_wxAuiManager *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiManager{
    wxAuiManager_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiManager;

void php_wxAuiManager_free(zend_object *object);
zend_object* php_wxAuiManager_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiManager_functions[] = {
    PHP_ME(php_wxAuiManager, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxAuiManager, Update, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, UnInit, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, ShowHint, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, SetManagedWindow, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, SetDockSizeConstraint, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, SetFlags, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, SavePerspective, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, SavePaneInfo, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, LoadPerspective, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, LoadPaneInfo, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, InsertPane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, HideHint, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, GetPane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, GetManager, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, GetManagedWindow, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, GetFlags, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, GetDockSizeConstraint, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, DetachPane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiManager, AddPane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxAuiManager * php_wxAuiManager_fetch_object(zend_object *obj) {
    return (zo_wxAuiManager *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiManager, zo)
    );
}

#define Z_wxAuiManager_P(zv) \
    php_wxAuiManager_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxAuiPaneInfo_entry;
extern zend_object_handlers wxphp_wxAuiPaneInfo_object_handlers;
void php_wxAuiPaneInfo_destruction_handler(zend_resource*);

class wxAuiPaneInfo_php: public wxAuiPaneInfo{
    public:

    wxAuiPaneInfo_php():wxAuiPaneInfo(){}
    wxAuiPaneInfo_php(const wxAuiPaneInfo& c):wxAuiPaneInfo(c){}
    
    

    ~wxAuiPaneInfo_php();

    struct _zo_wxAuiPaneInfo *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxAuiPaneInfo{
    wxAuiPaneInfo_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxAuiPaneInfo;

void php_wxAuiPaneInfo_free(zend_object *object);
zend_object* php_wxAuiPaneInfo_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxAuiPaneInfo_functions[] = {
    PHP_ME(php_wxAuiPaneInfo, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxAuiPaneInfo, Window, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, TopDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Top, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, ToolbarPane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Show, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, SetFlag, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, SafeSet, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Row, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, RightDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Right, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Resizable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Position, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, PinButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, PaneBorder, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Name, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Movable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, MinimizeButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, MinSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, MaximizeButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, MaxSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, LeftDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Left, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Layer, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsTopDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsToolbar, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsShown, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsRightDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsResizable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsOk, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsMovable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsLeftDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsFloating, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsFloatable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsFixed, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsDocked, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, IsBottomDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Icon, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Hide, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasPinButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasMinimizeButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasMaximizeButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasGripperTop, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasGripper, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasFlag, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasCloseButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasCaption, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, HasBorder, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, GripperTop, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Gripper, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, FloatingSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, FloatingPosition, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Floatable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Float, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Fixed, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Dockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, DockFixed, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Dock, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Direction, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, DestroyOnClose, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, DefaultPane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, CloseButton, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, CentrePane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Centre, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, CenterPane, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Center, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, CaptionVisible, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Caption, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, BottomDockable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, Bottom, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxAuiPaneInfo, BestSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxAuiPaneInfo * php_wxAuiPaneInfo_fetch_object(zend_object *obj) {
    return (zo_wxAuiPaneInfo *)(
        (char *)(obj) - XtOffsetOf(zo_wxAuiPaneInfo, zo)
    );
}

#define Z_wxAuiPaneInfo_P(zv) \
    php_wxAuiPaneInfo_fetch_object(Z_OBJ_P(zv))
#endif //WXPHP_AUI_H_GUARD
