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
    u1 flag;
    int max_locals;
    int max_stack;
    char *name;
    char *descriptor;
    u1 *bc;
} method_t;

typedef struct {
    u1 stat;
    class_file_t *cf;

    field_t *fields;
    method_t *methods;
} class_t;

// 在指定类中获取静态方法
method_t *find_special_static_method(class_t *cls, char *name, char *descriptor);

// 获取静态方法，递归
method_t *find_static_method(class_t *cls, char *name, char *descriptor);

// 在指定类中获取实例方法
method_t *find_special_method(class_t *cls, char *name, char *descriptor);

// 获取实例方法，递归
method_t *find_method(class_t *cls, char *name, char *descriptor);

// class loader
typedef struct {
    int cnt;
    char **paths;
} class_loader_t;

class_loader_t *class_loader_init(char cp[]);

void class_loader_destroy(class_loader_t *cl);

class_t *load_class(class_loader_t *cl, const char *name);

// end

// frame & env
typedef struct {
    int stat;
    uintptr_t *local_vars;
    uintptr_t *operand_stack;
    method_t *method;
    int pc;
} frame_t;

frame_t *frame_init(method_t *method);

typedef struct {
    int size;
    // 栈顶
    int top;
    // 栈帧
    frame_t **frame;

    // 异常码
    int code;
} env_t;

env_t *env_init(int size);

void env_destroy(env_t *env);

frame_t *env_top_frame(env_t *env);

void env_push(env_t *env, frame_t *frame);

frame_t *env_pop(env_t *env);

int env_empty(env_t *env);

typedef struct {
    // 执行环境
    env_t *env;
} meta_space_t;

meta_space_t *meta_space_init();

void set_main_env(meta_space_t *meta, env_t *env);

env_t *main_env(meta_space_t *meta);
// end


// utils
void println();

void println_string(const char *str);
// end

// global variables
// 错误码
int code;

#endif //MINI_JVM_C_JVM_H
