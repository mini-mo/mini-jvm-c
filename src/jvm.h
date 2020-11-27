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
} cp_info;

typedef struct {
    u2 attribute_name_index;
    u4 attribute_length;
    u1 *body;
} attribute_info;

typedef struct {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;
} method_info;

typedef struct {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info *attributes;
} field_info;

typedef struct {
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1 *code;
} code;

typedef struct {
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    cp_info *constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 *interfaces;
    u2 fields_count;
    field_info *fields;
    u2 methods_count;
    method_info *methods;
    u2 attributes_count;
    attribute_info *attributes;
} class_file;

// end class file

// reader
//u4 read_u4(FILE *file);
//u2 read_u2(FILE *file);
//u1 read_u1(FILE *file);

class_file *read_class_file(FILE *file);

#endif //MINI_JVM_C_JVM_H
