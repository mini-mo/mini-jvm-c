#include "jvm.h"

u1 read_u1(FILE *class_file) {
    int result = fgetc(class_file);
    assert(result != EOF && "Reached end of file prematurely");
    return (u1) result;
}

u2 read_u2(FILE *class_file) {
    return (u2) (read_u1(class_file) << 8 | read_u1(class_file));
}

u4 read_u4(FILE *class_file) {
    return (u4) (read_u2(class_file) << 16 | read_u2(class_file));
}

class_file_t *read_class_from_dir(const char *dir, const char *name) {
    size_t new_len = strlen(dir) + 1 + strlen(name) + 6;
    char *file_path = malloc(sizeof(char) * new_len + 1);
    file_path[new_len] = '\0';
    strcpy(file_path, dir);
    strcat(file_path, "/");
    strcat(file_path, name);
    strcat(file_path, ".class");

    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        return NULL;
    }
    class_file_t *cf = read_class_file(file);
    fclose(file);
    return cf;
}

// TODO help !!!
class_file_t *read_class_from_jar(const char *jar_path, const char *name) {
    fprintf(stderr, "need help for impl");
    return NULL;
}

class_file_t *read_class_file(FILE *file) {
    class_file_t *cf = malloc(sizeof(class_file_t));

    cf->magic = read_u4(file);
    cf->minor_version = read_u2(file);
    cf->major_version = read_u2(file);
    cf->constant_pool_count = read_u2(file);
    cf->constant_pool = malloc(sizeof(cp_info_t) * cf->constant_pool_count);
    // from 1

    for (u2 i = 1; i < cf->constant_pool_count; ++i) {
        cp_info_t *constant = &cf->constant_pool[i];
        constant->tag = read_u1(file);
        switch (constant->tag) {
            case CONSTANT_Utf8: {
                u2 len = read_u2(file);
                char *value = malloc(len + 1); // last for \0
                assert(value && "failed to allocate constant");
                size_t bytes_read = fread(value, 1, len, file);
                assert(bytes_read == len && "failed to read constant");
                value[len] = '\0';
                constant->info = (u1 *) value;
                break;
            }
            case CONSTANT_Fieldref:
            case CONSTANT_Methodref:
            case CONSTANT_InterfaceMethodref:
            case CONSTANT_InvokeDynamic:
            case CONSTANT_NameAndType:
            case CONSTANT_Integer:
            case CONSTANT_Float: {
                u2 len = 4;
                char *value = malloc(len); // last for \0
                assert(value && "failed to allocate constant");
                size_t bytes_read = fread(value, 1, len, file);
                assert(bytes_read == len && "failed to read constant");
                constant->info = (u1 *) value;
                break;
            }
            case CONSTANT_MethodHandle: {
                u2 len = 3;
                char *value = malloc(len); // last for \0
                assert(value && "failed to allocate constant");
                size_t bytes_read = fread(value, 1, len, file);
                assert(bytes_read == len && "failed to read constant");
                value[len] = '\0';
                constant->info = (u1 *) value;
                break;
            }
            case CONSTANT_Class:
            case CONSTANT_String:
            case CONSTANT_MethodType: {
                u2 len = 2;
                char *value = malloc(len); // last for \0
                assert(value && "failed to allocate constant");
                size_t bytes_read = fread(value, 1, len, file);
                assert(bytes_read == len && "failed to read constant");
                value[len] = '\0';
                constant->info = (u1 *) value;
                break;
            }
            case CONSTANT_Double:
            case CONSTANT_Long: {
                u2 len = 8;
                char *value = malloc(len); // last for \0
                assert(value && "failed to allocate constant");
                size_t bytes_read = fread(value, 1, len, file);
                assert(bytes_read == len && "failed to read constant");
                value[len] = '\0';
                constant->info = (u1 *) value;
                break;
            }
            default:
                fprintf(stderr, "unknown tag %d", constant->tag);
                exit(-1);
        }
    }

    cf->access_flags = read_u2(file);
    cf->this_class = read_u2(file);
    cf->super_class = read_u2(file);

    // interfaces
    cf->interfaces_count = read_u2(file);
    cf->interfaces = malloc(sizeof(u2) * cf->interfaces_count);
    for (int j = 0; j < cf->interfaces_count; ++j) {
        cf->interfaces[j] = read_u2(file);
    }

    // fields
    cf->fields_count = read_u2(file);
    cf->fields = malloc(sizeof(field_info_t) * cf->fields_count);
    for (int j = 0; j < cf->fields_count; ++j) {
        field_info_t *field = &cf->fields[j];
        field->access_flags = read_u2(file);
        field->name_index = read_u2(file);
        field->descriptor_index = read_u2(file);
        field->attributes_count = read_u2(file);
        field->attributes = malloc(sizeof(attribute_info_t) * field->attributes_count);
        for (int k = 0; k < field->attributes_count; ++k) {
            attribute_info_t *info = &field->attributes[k];
            info->attribute_name_index = read_u2(file);
            info->attribute_length = read_u4(file);
            char *body = malloc(sizeof(u1) * info->attribute_length);
            size_t bytes_read = fread(body, 1, info->attribute_length, file);
            assert(bytes_read == info->attribute_length && "failed to read constant");
            info->body = (u1 *) body;
        }
    }
    // methods
    cf->methods_count = read_u2(file);
    cf->methods = malloc(sizeof(method_info_t) * cf->methods_count);
    for (int j = 0; j < cf->methods_count; ++j) {
        method_info_t *method = &cf->methods[j];
        method->access_flags = read_u2(file);
        method->name_index = read_u2(file);
        method->descriptor_index = read_u2(file);
        method->attributes_count = read_u2(file);
        method->attributes = malloc(sizeof(attribute_info_t) * method->attributes_count);
        for (int k = 0; k < method->attributes_count; ++k) {
            attribute_info_t *info = &method->attributes[k];
            info->attribute_name_index = read_u2(file);
            info->attribute_length = read_u4(file);
            char *body = malloc(sizeof(u1) * info->attribute_length);
            size_t bytes_read = fread(body, 1, info->attribute_length, file);
            assert(bytes_read == info->attribute_length && "failed to read constant");
            info->body = (u1 *) body;
        }
    }

    // attributes
    cf->attributes_count = read_u2(file);
    cf->attributes = malloc(sizeof(attribute_info_t) * cf->attributes_count);
    for (int k = 0; k < cf->attributes_count; ++k) {
        attribute_info_t *info = &cf->attributes[k];
        info->attribute_name_index = read_u2(file);
        info->attribute_length = read_u4(file);
        char *body = malloc(sizeof(u1) * info->attribute_length);
        size_t bytes_read = fread(body, 1, info->attribute_length, file);
        assert(bytes_read == info->attribute_length && "failed to read constant");
        info->body = (u1 *) body;
    }

    return cf;
}