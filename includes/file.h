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

#ifndef WXPHP_FILE_H_GUARD
#define WXPHP_FILE_H_GUARD

#include "references.h"
#include "object_types.h"

ZEND_BEGIN_ARG_INFO_EX(wxphp_file_get_args, 0, 0, 1)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

extern zend_class_entry* php_wxFFile_entry;
extern zend_object_handlers wxphp_wxFFile_object_handlers;
void php_wxFFile_destruction_handler(zend_resource*);

class wxFFile_php: public wxFFile{
    public:

    wxFFile_php():wxFFile(){}
    wxFFile_php(const wxString& filename, const wxString& mode="r"):wxFFile(filename, mode){}
    
    

    ~wxFFile_php();

    struct _zo_wxFFile *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxFFile{
    wxFFile_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxFFile;

void php_wxFFile_free(zend_object *object);
zend_object* php_wxFFile_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxFFile_functions[] = {
    PHP_ME(php_wxFFile, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxFFile, Write, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Tell, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, SeekEnd, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Seek, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Read, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Open, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Length, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, IsOpened, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, GetKind, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Flush, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Error, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Eof, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFFile, Close, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxFFile * php_wxFFile_fetch_object(zend_object *obj) {
    return (zo_wxFFile *)(
        (char *)(obj) - XtOffsetOf(zo_wxFFile, zo)
    );
}

#define Z_wxFFile_P(zv) \
    php_wxFFile_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxFile_entry;
extern zend_object_handlers wxphp_wxFile_object_handlers;
void php_wxFile_destruction_handler(zend_resource*);

class wxFile_php: public wxFile{
    public:

    wxFile_php():wxFile(){}
    wxFile_php(const wxString& filename, wxFile::OpenMode mode=wxFile::read):wxFile(filename, mode){}
    wxFile_php(int fd):wxFile(fd){}
    
    

    ~wxFile_php();

    struct _zo_wxFile *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxFile{
    wxFile_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxFile;

void php_wxFile_free(zend_object *object);
zend_object* php_wxFile_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxFile_functions[] = {
    PHP_ME(php_wxFile, Seek, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, SeekEnd, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Tell, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Write, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, fd, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxFile, Open, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Length, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, IsOpened, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, GetLastError, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, GetKind, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Flush, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Exists, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Eof, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Create, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Close, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, ClearLastError, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Attach, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Detach, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFile, Access, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxFile * php_wxFile_fetch_object(zend_object *obj) {
    return (zo_wxFile *)(
        (char *)(obj) - XtOffsetOf(zo_wxFile, zo)
    );
}

#define Z_wxFile_P(zv) \
    php_wxFile_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxPathList_entry;
extern zend_object_handlers wxphp_wxPathList_object_handlers;
void php_wxPathList_destruction_handler(zend_resource*);

class wxPathList_php: public wxPathList{
    public:

    wxPathList_php():wxPathList(){}
    wxPathList_php(const wxArrayString& arr):wxPathList(arr){}
    
    

    ~wxPathList_php();

    struct _zo_wxPathList *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxPathList{
    wxPathList_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxPathList;

void php_wxPathList_free(zend_object *object);
zend_object* php_wxPathList_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxPathList_functions[] = {
    PHP_ME(php_wxPathList, Add, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxPathList, AddEnvList, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxPathList, EnsureFileAccessible, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxPathList, FindAbsoluteValidPath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxPathList, FindValidPath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxPathList, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_FE_END
};
#endif


static inline zo_wxPathList * php_wxPathList_fetch_object(zend_object *obj) {
    return (zo_wxPathList *)(
        (char *)(obj) - XtOffsetOf(zo_wxPathList, zo)
    );
}

#define Z_wxPathList_P(zv) \
    php_wxPathList_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxFileName_entry;
extern zend_object_handlers wxphp_wxFileName_object_handlers;
void php_wxFileName_destruction_handler(zend_resource*);

class wxFileName_php: public wxFileName{
    public:

    wxFileName_php():wxFileName(){}
    wxFileName_php(const wxFileName& filename):wxFileName(filename){}
    wxFileName_php(const wxString& fullpath, wxPathFormat format=wxPATH_NATIVE):wxFileName(fullpath, format){}
    wxFileName_php(const wxString& path, const wxString& name, wxPathFormat format=wxPATH_NATIVE):wxFileName(path, name, format){}
    wxFileName_php(const wxString& path, const wxString& name, const wxString& ext, wxPathFormat format=wxPATH_NATIVE):wxFileName(path, name, ext, format){}
    wxFileName_php(const wxString& volume, const wxString& path, const wxString& name, const wxString& ext, wxPathFormat format=wxPATH_NATIVE):wxFileName(volume, path, name, ext, format){}
    
    

    ~wxFileName_php();

    struct _zo_wxFileName *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxFileName{
    wxFileName_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxFileName;

void php_wxFileName_free(zend_object *object);
zend_object* php_wxFileName_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxFileName_functions[] = {
    PHP_ME(php_wxFileName, AppendDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, InsertDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, Assign, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxFileName, Touch, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, StripExtension, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SplitVolume, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SplitPath, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetVolume, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetTimes, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetPath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetName, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetFullName, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetExt, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetEmptyExt, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SetCwd, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, SameAs, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, Rmdir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, ReplaceHomeDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, ReplaceEnvVariable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, RemoveLastDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, RemoveDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, PrependDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, AssignCwd, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, AssignDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, AssignHomeDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, AssignTempFileName, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, Clear, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, ClearExt, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, CreateTempFileName, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, DirExists, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, DirName, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, FileExists, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, FileName, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetCwd, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetDirCount, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetDirs, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetExt, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetForbiddenChars, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetFormat, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetFullName, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetFullPath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetHomeDir, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetHumanReadableSize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetLongPath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetName, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetModificationTime, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetPath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetPathSeparators, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetPathTerminators, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetPathWithSep, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetShortPath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetTempDir, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetVolumeSeparator, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, GetVolume, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, HasExt, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, HasName, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, HasVolume, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsAbsolute, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsCaseSensitive, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsDirReadable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsDirWritable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsFileExecutable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsFileReadable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsFileWritable, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsMSWUniqueVolumeNamePath, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsOk, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, IsRelative, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, MakeAbsolute, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, MakeRelativeTo, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, Mkdir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileName, Normalize, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxFileName * php_wxFileName_fetch_object(zend_object *obj) {
    return (zo_wxFileName *)(
        (char *)(obj) - XtOffsetOf(zo_wxFileName, zo)
    );
}

#define Z_wxFileName_P(zv) \
    php_wxFileName_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxFSFile_entry;
extern zend_object_handlers wxphp_wxFSFile_object_handlers;
void php_wxFSFile_destruction_handler(zend_resource*);

class wxFSFile_php: public wxFSFile{
    public:

    wxFSFile_php(wxInputStream* stream, const wxString& location, const wxString& mimetype, const wxString& anchor, wxDateTime modif):wxFSFile(stream, location, mimetype, anchor, modif){}
    
    

    ~wxFSFile_php();

    struct _zo_wxFSFile *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxFSFile{
    wxFSFile_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxFSFile;

void php_wxFSFile_free(zend_object *object);
zend_object* php_wxFSFile_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxFSFile_functions[] = {
    PHP_ME(php_wxFSFile, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(php_wxFSFile, GetStream, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFSFile, GetModificationTime, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFSFile, GetMimeType, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFSFile, GetLocation, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFSFile, GetAnchor, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFSFile, DetachStream, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxFSFile * php_wxFSFile_fetch_object(zend_object *obj) {
    return (zo_wxFSFile *)(
        (char *)(obj) - XtOffsetOf(zo_wxFSFile, zo)
    );
}

#define Z_wxFSFile_P(zv) \
    php_wxFSFile_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxFileSystemWatcher_entry;
extern zend_object_handlers wxphp_wxFileSystemWatcher_object_handlers;
void php_wxFileSystemWatcher_destruction_handler(zend_resource*);

class wxFileSystemWatcher_php: public wxFileSystemWatcher{
    public:

    wxFileSystemWatcher_php():wxFileSystemWatcher(){}
    
    

    ~wxFileSystemWatcher_php();

    struct _zo_wxFileSystemWatcher *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxFileSystemWatcher{
    wxFileSystemWatcher_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxFileSystemWatcher;

void php_wxFileSystemWatcher_free(zend_object *object);
zend_object* php_wxFileSystemWatcher_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxFileSystemWatcher_functions[] = {
    PHP_ME(php_wxFileSystemWatcher, Add, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileSystemWatcher, AddTree, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileSystemWatcher, GetWatchedPathsCount, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileSystemWatcher, Remove, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileSystemWatcher, RemoveAll, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileSystemWatcher, RemoveTree, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileSystemWatcher, SetOwner, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxFileSystemWatcher, __construct, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_FE_END
};
#endif


static inline zo_wxFileSystemWatcher * php_wxFileSystemWatcher_fetch_object(zend_object *obj) {
    return (zo_wxFileSystemWatcher *)(
        (char *)(obj) - XtOffsetOf(zo_wxFileSystemWatcher, zo)
    );
}

#define Z_wxFileSystemWatcher_P(zv) \
    php_wxFileSystemWatcher_fetch_object(Z_OBJ_P(zv))
extern zend_class_entry* php_wxStandardPaths_entry;
extern zend_object_handlers wxphp_wxStandardPaths_object_handlers;
void php_wxStandardPaths_destruction_handler(zend_resource*);

class wxStandardPaths_php: public wxStandardPaths{
    public:

    
    

    ~wxStandardPaths_php();

    struct _zo_wxStandardPaths *zo = NULL;
    zval phpObj;
    wxPHPObjectReferences references;
};

BEGIN_EXTERN_C()
typedef struct _zo_wxStandardPaths{
    wxStandardPaths_php* native_object;
    wxphp_object_type object_type;
    int is_user_initialized;
    zend_object zo;
} zo_wxStandardPaths;

void php_wxStandardPaths_free(zend_object *object);
zend_object* php_wxStandardPaths_new(zend_class_entry *class_type);
END_EXTERN_C()

#ifdef WXPHP_INCLUDE_METHOD_TABLES
static zend_function_entry php_wxStandardPaths_functions[] = {
    PHP_ME(php_wxStandardPaths, Get, arginfo_tmp_placeholder, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetAppDocumentsDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetConfigDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetDataDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetDocumentsDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetExecutablePath, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetLocalDataDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetPluginsDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetResourcesDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetTempDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetUserConfigDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetUserDataDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, GetUserLocalDataDir, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_ME(php_wxStandardPaths, UseAppInfo, arginfo_tmp_placeholder, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
#endif


static inline zo_wxStandardPaths * php_wxStandardPaths_fetch_object(zend_object *obj) {
    return (zo_wxStandardPaths *)(
        (char *)(obj) - XtOffsetOf(zo_wxStandardPaths, zo)
    );
}

#define Z_wxStandardPaths_P(zv) \
    php_wxStandardPaths_fetch_object(Z_OBJ_P(zv))
#endif //WXPHP_FILE_H_GUARD
