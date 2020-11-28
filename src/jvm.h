#ifndef MINI_JVM_C_JVM_H
#define MINI_JVM_C_JVM_H

#include <inttypes.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

// types
typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

// class file type
typedef struct {
    u1 tag;
    u1 *info;
} cp_info_t;

typedef struct {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *body;
} attribute_info_t;

typedef struct {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info_t *attributes;
} method_info_t;

typedef struct {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info_t *attributes;
} field_info_t;

typedef struct {
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1 *code;
} code_t;

typedef struct {
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    cp_info_t *constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 *interfaces;
    u2 fields_count;
    field_info_t *fields;
    u2 methods_count;
    method_info_t *methods;
    u2 attributes_count;
    attribute_info_t *attributes;
} class_file_t;

class_file_t *read_class_file(FILE *file);

class_file_t *read_class_from_dir(const char *filepath, const char *name);

/*
 * 尝试从 jar 文件内根据类名加载
 *
 * @param jar_path jar 文件路径
 * @param name 类名，e.g java/lang/Object
 * @return NULl if failed
 */
class_file_t *read_class_from_jar(const char *jar_path, const char *name);

// end class file

// class
typedef struct {
} field_t;

typedef struct {
} method_t;

typedef struct {
    u1 stat;
    class_file_t *cf;

    field_t *fields;
    method_t *methods;
} class_t;

// class loader
typedef struct {
    int cnt;
    char **paths;
} class_loader_t;

class_loader_t *class_loader_init(char cp[]);

void class_loader_destroy(class_loader_t *cl);

class_t *load_class(class_loader_t *cl, const char *name);

// end


// utils
void println();

void println_string(const char *str);
// end
#endif //MINI_JVM_C_JVM_H
