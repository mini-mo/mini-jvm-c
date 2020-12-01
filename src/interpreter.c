#include "jvm.h"

void execute() {
    {
        while (!env_empty(env)) {
            frame_t *tf = env_top_frame(env);
            u1 *bc = tf->method->bc;
            uintptr_t *local_vars = tf->local_vars;
            uintptr_t *operand_stack = tf->operand_stack;

            while (1) {
                u1 tag = *bc;
                switch (tag) {
                    case ICONST_0: {
                        uintptr_t tos = 0;
                        *operand_stack++ = tos;
                        bc++;
                        break;
                    }
                    case ICONST_1: {
                        uintptr_t tos = 1;
                        *operand_stack++ = tos;
                        bc++;
                        break;
                    }
                    case BIPUSH: {
                        uintptr_t tos = bc[1];
                        *operand_stack++ = tos;
                        bc += 2;
                        break;
                    }
                    case ILOAD_0: {
                        uintptr_t tos = local_vars[0];
                        *operand_stack++ = tos;
                        bc++;
                        break;
                    }
                    case ILOAD_1: {
                        uintptr_t tos = local_vars[1];
                        *operand_stack++ = tos;
                        bc++;
                        break;
                    }
                    case ILOAD_2: {
                        uintptr_t tos = local_vars[2];
                        *operand_stack++ = tos;
                        bc++;
                        break;
                    }
                    case ISTORE_0: {
                        local_vars[0] = *--operand_stack;
                        bc++;
                        break;
                    }
                    case ISTORE_1: {
                        local_vars[1] = *--operand_stack;
                        bc++;
                        break;
                    }
                    case ISTORE_2: {
                        local_vars[2] = *--operand_stack;
                        bc++;
                        break;
                    }
                    case IF_ICMPGT: {
                        uintptr_t os = (bc[1] << 8) | bc[2];
                        uintptr_t v2 = *--operand_stack;
                        uintptr_t v1 = *--operand_stack;
                        if (v1 > v2) {
                            bc += os;
                        } else {
                            bc += 3;
                        }
                        break;
                    }
                    case IADD: {
                        uintptr_t v2 = *--operand_stack;
                        uintptr_t v1 = *--operand_stack;
                        *operand_stack++ = v1 + v2;
                        bc++;
                        break;
                    }
                    case IINC: {
                        uintptr_t li = bc[1];
                        uintptr_t val = bc[2];
                        local_vars[li] = local_vars[li] + val;
                        bc += 3;
                        break;
                    }
                    case IRETURN: {
                        printf("%d\n", *--operand_stack);
                        bc++;
                        goto end;
                    }
                    case GOTO: {
                        int tmp = (signed short) ((bc[1] << 8) | (bc)[2]);
                        bc += tmp;
                        break;
                    }
                    default: {
                        fprintf(stderr, "xxx");
                        exit(-1);
                        break;
                    }
                }
            }

        }
    }
    end:
    return;
}
