#include <stdio.h>
#include "jvm.h"

code_t *parse_code(method_info_t mi, cp_info_t *cp);

int main(int argc, char **argv) {
    if (argc < 2) {
        println_string("must provide class path");
        return -1;
    }

    // FIXME user parameters
    class_loader_t *cl = class_loader_init("misc:jre");

    char *main_class = strdup(argv[1]);
    char *cpntr;
    for (cpntr = main_class; *cpntr; cpntr++) {
        if (*cpntr == '.') {
            *cpntr = '/';
        }
    }
    class_t *cls = load_class(cl, main_class);
    class_file_t *cf = cls->cf;

    method_info_t mi = cf->methods[1];
    code_t *code = parse_code(mi, cf->constant_pool);

    u1 *bc = code->code;
    uintptr_t *local_vars = malloc(sizeof(uintptr_t) * code->max_locals);
    uintptr_t *ostack = malloc(sizeof(uintptr_t) * code->max_stack);
    int pc = 0;
    for (;;) {
        u1 tag = bc[pc];
        switch (tag) {
            case 0x04: {
                uintptr_t tos = 1;
                *ostack++ = tos;
                pc++;
                break;
            }
            case 0x3b: {
                local_vars[0] = *--ostack;
                pc++;
                break;
            }
            case 0x1a: {
                uintptr_t tos = local_vars[0];
                *ostack++ = tos;
                pc++;
                break;
            }
            case 0xac: {
                printf("%d\n", *--ostack);
                pc++;
                goto end;
            }
            default:
                fprintf(stderr, "xxx");
                exit(-1);
                break;
        }
    }

    end:

    return 0;
}

code_t *parse_code(method_info_t mi, cp_info_t *cp) {
    for (int i = 0; i < mi.attributes_count; ++i) {
        attribute_info_t info = mi.attributes[i];
        u2 ni = info.attribute_name_index;
        cp_info_t cpi = cp[ni];
        if (cpi.tag != CONSTANT_Utf8) {
            continue;
        }
        if (strcmp((char *) cpi.info, "Code") != 0) {
            continue;
        }

        u1 *bytes = info.body;
        code_t *code = malloc(sizeof(code_t));
        code->max_stack = (bytes[0] << 8) | bytes[1];
        bytes += 2;
        code->max_locals = (bytes[0] << 8) | bytes[1];
        bytes += 2;
        code->code_length = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
        bytes += 4;
        u1 *cb = malloc(sizeof(u1) * code->code_length);
        memcpy(cb, bytes, code->code_length);
        code->code = cb;

        return code;
    };

    return NULL;
}
