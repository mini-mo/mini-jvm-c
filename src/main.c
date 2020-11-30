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
//        printf("%x\n", tag);
        switch (tag) {
            case ICONST_0: {
                uintptr_t tos = 0;
                *ostack++ = tos;
                pc++;
                break;
            }
            case ICONST_1: {
                uintptr_t tos = 1;
                *ostack++ = tos;
                pc++;
                break;
            }
            case BIPUSH: {
                uintptr_t tos = bc[pc + 1];
                *ostack++ = tos;
                pc += 2;
                break;
            }
            case ILOAD_0: {
                uintptr_t tos = local_vars[0];
                *ostack++ = tos;
                pc++;
                break;
            }
            case ILOAD_1: {
                uintptr_t tos = local_vars[1];
                *ostack++ = tos;
                pc++;
                break;
            }
            case ILOAD_2: {
                uintptr_t tos = local_vars[2];
                *ostack++ = tos;
                pc++;
                break;
            }
            case ISTORE_0: {
                local_vars[0] = *--ostack;
                pc++;
                break;
            }
            case ISTORE_1: {
                local_vars[1] = *--ostack;
                pc++;
                break;
            }
            case ISTORE_2: {
                local_vars[2] = *--ostack;
                pc++;
                break;
            }
            case IF_ICMPGT: {
                uintptr_t os = (bc[pc + 1] << 8) | bc[pc + 2];
                uintptr_t v2 = *--ostack;
                uintptr_t v1 = *--ostack;
                if (v1 > v2) {
                    pc += os;
                } else {
                    pc += 3;
                }
                break;
            }
            case IADD: {
                uintptr_t v2 = *--ostack;
                uintptr_t v1 = *--ostack;
                *ostack++ = v1 + v2;
                pc++;
                break;
            }
            case IINC: {
                uintptr_t li = bc[pc + 1];
                uintptr_t val = bc[pc + 2];
                local_vars[li] = local_vars[li] + val;
                pc += 3;
                break;
            }
            case IRETURN: {
                printf("%d\n", *--ostack);
                pc++;
                goto end;
            }
            case GOTO: {
                int tmp = (signed short) ((bc[pc + 1] << 8) | (bc)[pc + 2]);
                pc += tmp;
                break;
            }
            default: {
                fprintf(stderr, "xxx");
                exit(-1);
                break;
            }
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
