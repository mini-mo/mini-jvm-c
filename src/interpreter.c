#include "jvm.h"

static void execute() {
    while (!env_empty(env)) {
        frame_t *tf = env_top_frame(env);
        u1 *bc = tf->method->bc;
        uintptr_t *local_vars = tf->local_vars;
        uintptr_t *operand_stack = tf->operand_stack;

        while (*bc) {
            u1 tag = *bc;
            switch (tag) {
                // const
                case NOP : {
                    fprintf(stderr, " nop ");
                    bc++;
                    break;
                }
                case ACONST_NULL : {
                    fprintf(stderr, " aconst_null ");
                    bc++;
                    break;
                }
                case ICONST_M1 : {
                    fprintf(stderr, " iconst_m1 ");
                    bc++;
                    break;
                }
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
                case ICONST_2 : {
                    uintptr_t tos = 2;
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case ICONST_3 : {
                    uintptr_t tos = 3;
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case ICONST_4 : {
                    uintptr_t tos = 4;
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case ICONST_5 : {
                    uintptr_t tos = 5;
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case LCONST_0 : {
                    uint64_t val = 0;
                    *(uint64_t *) &operand_stack[0 * 2] = val;
                    operand_stack += 2;
                    bc++;
                    break;
                }
                case LCONST_1 : {
                    uint64_t val = 1;
                    *(uint64_t *) &operand_stack[0 * 2] = val;
                    operand_stack += 2;
                    bc++;
                    break;
                }
                case FCONST_0 : {
                    uintptr_t tos = 0;
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case FCONST_1 : {
                    uintptr_t tos = 1;
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case FCONST_2 : {
                    uintptr_t tos = 2;
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case DCONST_0 : {
                    uint64_t val = 0;
                    *(uint64_t *) &operand_stack[0 * 2] = val;
                    operand_stack += 2;
                    bc++;
                    break;
                }
                case DCONST_1 : {
                    uint64_t val = 1;
                    *(uint64_t *) &operand_stack[0 * 2] = val;
                    operand_stack += 2;
                    bc++;
                    break;
                }
                case BIPUSH: {
                    uintptr_t tos = bc[1];
                    *operand_stack++ = tos;
                    bc += 2;
                    break;
                }
                case SIPUSH : {
                    uintptr_t tos = (signed short) (((bc)[1] << 8) | (bc)[2]);
                    *operand_stack++ = tos;
                    bc++;
                    break;
                }
                case LDC : {
                    fprintf(stderr, " ldc ");
                    bc++;
                    break;
                }
                case LDC_W : {
                    fprintf(stderr, " ldc_w ");
                    bc++;
                    break;
                }
                case LDC2_W : {
                    fprintf(stderr, " ldc2_w ");
                    bc++;
                    break;
                }

                    // loads
                case ILOAD : {
                    fprintf(stderr, " iload ");
                    bc++;
                    break;
                }
                case LLOAD : {
                    fprintf(stderr, " lload ");
                    bc++;
                    break;
                }
                case FLOAD : {
                    fprintf(stderr, " fload ");
                    bc++;
                    break;
                }
                case DLOAD : {
                    fprintf(stderr, " dload ");
                    bc++;
                    break;
                }
                case ALOAD : {
                    fprintf(stderr, " aload ");
                    bc++;
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
                case ILOAD_3 : {
                    fprintf(stderr, " iload_3 ");
                    bc++;
                    break;
                }
                case LLOAD_0 : {
                    fprintf(stderr, " lload_0 ");
                    bc++;
                    break;
                }
                case LLOAD_1 : {
                    fprintf(stderr, " lload_1 ");
                    bc++;
                    break;
                }
                case LLOAD_2 : {
                    fprintf(stderr, " lload_2 ");
                    bc++;
                    break;
                }
                case LLOAD_3 : {
                    fprintf(stderr, " lload_3 ");
                    bc++;
                    break;
                }
                case FLOAD_0 : {
                    fprintf(stderr, " fload_0 ");
                    bc++;
                    break;
                }
                case FLOAD_1 : {
                    fprintf(stderr, " fload_1 ");
                    bc++;
                    break;
                }
                case FLOAD_2 : {
                    fprintf(stderr, " fload_2 ");
                    bc++;
                    break;
                }
                case FLOAD_3 : {
                    fprintf(stderr, " fload_3 ");
                    bc++;
                    break;
                }
                case DLOAD_0 : {
                    fprintf(stderr, " dload_0 ");
                    bc++;
                    break;
                }
                case DLOAD_1 : {
                    fprintf(stderr, " dload_1 ");
                    bc++;
                    break;
                }
                case DLOAD_2 : {
                    fprintf(stderr, " dload_2 ");
                    bc++;
                    break;
                }
                case DLOAD_3 : {
                    fprintf(stderr, " dload_3 ");
                    bc++;
                    break;
                }
                case ALOAD_0 : {
                    fprintf(stderr, " aload_0 ");
                    bc++;
                    break;
                }
                case ALOAD_1 : {
                    fprintf(stderr, " aload_1 ");
                    bc++;
                    break;
                }
                case ALOAD_2 : {
                    fprintf(stderr, " aload_2 ");
                    bc++;
                    break;
                }
                case ALOAD_3 : {
                    fprintf(stderr, " aload_3 ");
                    bc++;
                    break;
                }
                case IALOAD : {
                    fprintf(stderr, " iaload ");
                    bc++;
                    break;
                }
                case LALOAD : {
                    fprintf(stderr, " laload ");
                    bc++;
                    break;
                }
                case FALOAD : {
                    fprintf(stderr, " faload ");
                    bc++;
                    break;
                }
                case DALOAD : {
                    fprintf(stderr, " daload ");
                    bc++;
                    break;
                }
                case AALOAD : {
                    fprintf(stderr, " aaload ");
                    bc++;
                    break;
                }
                case BALOAD : {
                    fprintf(stderr, " baload ");
                    bc++;
                    break;
                }
                case CALOAD : {
                    fprintf(stderr, " caload ");
                    bc++;
                    break;
                }
                case SALOAD : {
                    fprintf(stderr, " saload ");
                    bc++;
                    break;
                }
                case ISTORE : {
                    fprintf(stderr, " istore ");
                    bc++;
                    break;
                }
                case LSTORE : {
                    fprintf(stderr, " lstore ");
                    bc++;
                    break;
                }
                case FSTORE : {
                    fprintf(stderr, " fstore ");
                    bc++;
                    break;
                }
                case DSTORE : {
                    fprintf(stderr, " dstore ");
                    bc++;
                    break;
                }
                case ASTORE : {
                    fprintf(stderr, " astore ");
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
                case ISTORE_3 : {
                    fprintf(stderr, " istore_3 ");
                    bc++;
                    break;
                }
                case LSTORE_0 : {
                    fprintf(stderr, " lstore_0 ");
                    bc++;
                    break;
                }
                case LSTORE_1 : {
                    fprintf(stderr, " lstore_1 ");
                    bc++;
                    break;
                }
                case LSTORE_2 : {
                    fprintf(stderr, " lstore_2 ");
                    bc++;
                    break;
                }
                case LSTORE_3 : {
                    fprintf(stderr, " lstore_3 ");
                    bc++;
                    break;
                }
                case FSTORE_0 : {
                    fprintf(stderr, " fstore_0 ");
                    bc++;
                    break;
                }
                case FSTORE_1 : {
                    fprintf(stderr, " fstore_1 ");
                    bc++;
                    break;
                }
                case FSTORE_2 : {
                    fprintf(stderr, " fstore_2 ");
                    bc++;
                    break;
                }
                case FSTORE_3 : {
                    fprintf(stderr, " fstore_3 ");
                    bc++;
                    break;
                }
                case DSTORE_0 : {
                    fprintf(stderr, " dstore_0 ");
                    bc++;
                    break;
                }
                case DSTORE_1 : {
                    fprintf(stderr, " dstore_1 ");
                    bc++;
                    break;
                }
                case DSTORE_2 : {
                    fprintf(stderr, " dstore_2 ");
                    bc++;
                    break;
                }
                case DSTORE_3 : {
                    fprintf(stderr, " dstore_3 ");
                    bc++;
                    break;
                }
                case ASTORE_0 : {
                    fprintf(stderr, " astore_0 ");
                    bc++;
                    break;
                }
                case ASTORE_1 : {
                    fprintf(stderr, " astore_1 ");
                    bc++;
                    break;
                }
                case ASTORE_2 : {
                    fprintf(stderr, " astore_2 ");
                    bc++;
                    break;
                }
                case ASTORE_3 : {
                    fprintf(stderr, " astore_3 ");
                    bc++;
                    break;
                }
                case IASTORE : {
                    fprintf(stderr, " iastore ");
                    bc++;
                    break;
                }
                case LASTORE : {
                    fprintf(stderr, " lastore ");
                    bc++;
                    break;
                }
                case FASTORE : {
                    fprintf(stderr, " fastore ");
                    bc++;
                    break;
                }
                case DASTORE : {
                    fprintf(stderr, " dastore ");
                    bc++;
                    break;
                }
                case AASTORE : {
                    fprintf(stderr, " aastore ");
                    bc++;
                    break;
                }
                case BASTORE : {
                    fprintf(stderr, " bastore ");
                    bc++;
                    break;
                }
                case CASTORE : {
                    fprintf(stderr, " castore ");
                    bc++;
                    break;
                }
                case SASTORE : {
                    fprintf(stderr, " sastore ");
                    bc++;
                    break;
                }
                case POP : {
                    fprintf(stderr, " pop ");
                    bc++;
                    break;
                }
                case POP2 : {
                    fprintf(stderr, " pop2 ");
                    bc++;
                    break;
                }
                case DUP : {
                    fprintf(stderr, " dup ");
                    bc++;
                    break;
                }
                case DUP_X1 : {
                    fprintf(stderr, " dup_x1 ");
                    bc++;
                    break;
                }
                case DUP_X2 : {
                    fprintf(stderr, " dup_x2 ");
                    bc++;
                    break;
                }
                case DUP2 : {
                    fprintf(stderr, " dup2 ");
                    bc++;
                    break;
                }
                case DUP2_X1 : {
                    fprintf(stderr, " dup2_x1 ");
                    bc++;
                    break;
                }
                case DUP2_X2 : {
                    fprintf(stderr, " dup2_x2 ");
                    bc++;
                    break;
                }
                case SWAP : {
                    fprintf(stderr, " swap ");
                    bc++;
                    break;
                }
                case IADD: {
                    uintptr_t v2 = *--operand_stack;
                    uintptr_t v1 = *--operand_stack;
                    *operand_stack++ = v1 + v2;
                    bc++;
                    break;
                }
                case LADD : {
                    fprintf(stderr, " ladd ");
                    bc++;
                    break;
                }
                case FADD : {
                    fprintf(stderr, " fadd ");
                    bc++;
                    break;
                }
                case DADD : {
                    fprintf(stderr, " dadd ");
                    bc++;
                    break;
                }
                case ISUB : {
                    fprintf(stderr, " isub ");
                    bc++;
                    break;
                }
                case LSUB : {
                    fprintf(stderr, " lsub ");
                    bc++;
                    break;
                }
                case FSUB : {
                    fprintf(stderr, " fsub ");
                    bc++;
                    break;
                }
                case DSUB : {
                    fprintf(stderr, " dsub ");
                    bc++;
                    break;
                }
                case IMUL : {
                    fprintf(stderr, " imul ");
                    bc++;
                    break;
                }
                case LMUL : {
                    fprintf(stderr, " lmul ");
                    bc++;
                    break;
                }
                case FMUL : {
                    fprintf(stderr, " fmul ");
                    bc++;
                    break;
                }
                case DMUL : {
                    fprintf(stderr, " dmul ");
                    bc++;
                    break;
                }
                case IDIV : {
                    fprintf(stderr, " idiv ");
                    bc++;
                    break;
                }
                case LDIV : {
                    fprintf(stderr, " ldiv ");
                    bc++;
                    break;
                }
                case FDIV : {
                    fprintf(stderr, " fdiv ");
                    bc++;
                    break;
                }
                case DDIV : {
                    fprintf(stderr, " ddiv ");
                    bc++;
                    break;
                }
                case IREM : {
                    fprintf(stderr, " irem ");
                    bc++;
                    break;
                }
                case LREM : {
                    fprintf(stderr, " lrem ");
                    bc++;
                    break;
                }
                case FREM : {
                    fprintf(stderr, " frem ");
                    bc++;
                    break;
                }
                case DREM : {
                    fprintf(stderr, " drem ");
                    bc++;
                    break;
                }
                case INEG : {
                    fprintf(stderr, " ineg ");
                    bc++;
                    break;
                }
                case LNEG : {
                    fprintf(stderr, " lneg ");
                    bc++;
                    break;
                }
                case FNEG : {
                    fprintf(stderr, " fneg ");
                    bc++;
                    break;
                }
                case DNEG : {
                    fprintf(stderr, " dneg ");
                    bc++;
                    break;
                }
                case ISHL : {
                    fprintf(stderr, " ishl ");
                    bc++;
                    break;
                }
                case LSHL : {
                    fprintf(stderr, " lshl ");
                    bc++;
                    break;
                }
                case ISHR : {
                    fprintf(stderr, " ishr ");
                    bc++;
                    break;
                }
                case LSHR : {
                    fprintf(stderr, " lshr ");
                    bc++;
                    break;
                }
                case IUSHR : {
                    fprintf(stderr, " iushr ");
                    bc++;
                    break;
                }
                case LUSHR : {
                    fprintf(stderr, " lushr ");
                    bc++;
                    break;
                }
                case IAND : {
                    fprintf(stderr, " iand ");
                    bc++;
                    break;
                }
                case LAND : {
                    fprintf(stderr, " land ");
                    bc++;
                    break;
                }
                case IOR : {
                    fprintf(stderr, " ior ");
                    bc++;
                    break;
                }
                case LOR : {
                    fprintf(stderr, " lor ");
                    bc++;
                    break;
                }
                case IXOR : {
                    fprintf(stderr, " ixor ");
                    bc++;
                    break;
                }
                case LXOR : {
                    fprintf(stderr, " lxor ");
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
                case I2L : {
                    fprintf(stderr, " i2l ");
                    bc++;
                    break;
                }
                case I2F : {
                    fprintf(stderr, " i2f ");
                    bc++;
                    break;
                }
                case I2D : {
                    fprintf(stderr, " i2d ");
                    bc++;
                    break;
                }
                case L2I : {
                    fprintf(stderr, " l2i ");
                    bc++;
                    break;
                }
                case L2F : {
                    fprintf(stderr, " l2f ");
                    bc++;
                    break;
                }
                case L2D : {
                    fprintf(stderr, " l2d ");
                    bc++;
                    break;
                }
                case F2I : {
                    fprintf(stderr, " f2i ");
                    bc++;
                    break;
                }
                case F2L : {
                    fprintf(stderr, " f2l ");
                    bc++;
                    break;
                }
                case F2D : {
                    fprintf(stderr, " f2d ");
                    bc++;
                    break;
                }
                case D2I : {
                    fprintf(stderr, " d2i ");
                    bc++;
                    break;
                }
                case D2L : {
                    fprintf(stderr, " d2l ");
                    bc++;
                    break;
                }
                case D2F : {
                    fprintf(stderr, " d2f ");
                    bc++;
                    break;
                }
                case I2B : {
                    fprintf(stderr, " i2b ");
                    bc++;
                    break;
                }
                case I2C : {
                    fprintf(stderr, " i2c ");
                    bc++;
                    break;
                }
                case I2S : {
                    fprintf(stderr, " i2s ");
                    bc++;
                    break;
                }
                case LCMP : {
                    fprintf(stderr, " lcmp ");
                    bc++;
                    break;
                }
                case FCMPL : {
                    fprintf(stderr, " fcmpl ");
                    bc++;
                    break;
                }
                case FCMPG : {
                    fprintf(stderr, " fcmpg ");
                    bc++;
                    break;
                }
                case DCMPL : {
                    fprintf(stderr, " dcmpl ");
                    bc++;
                    break;
                }
                case DCMPG : {
                    fprintf(stderr, " dcmpg ");
                    bc++;
                    break;
                }
                case IFEQ : {
                    fprintf(stderr, " ifeq ");
                    bc++;
                    break;
                }
                case IFNE : {
                    fprintf(stderr, " ifne ");
                    bc++;
                    break;
                }
                case IFLT : {
                    fprintf(stderr, " iflt ");
                    bc++;
                    break;
                }
                case IFGE : {
                    fprintf(stderr, " ifge ");
                    bc++;
                    break;
                }
                case IFGT : {
                    fprintf(stderr, " ifgt ");
                    bc++;
                    break;
                }
                case IFLE : {
                    fprintf(stderr, " ifle ");
                    bc++;
                    break;
                }
                case IF_ICMPEQ : {
                    fprintf(stderr, " if_icmpeq ");
                    bc++;
                    break;
                }
                case IF_ICMPNE : {
                    fprintf(stderr, " if_icmpne ");
                    bc++;
                    break;
                }
                case IF_ICMPLT : {
                    fprintf(stderr, " if_icmplt ");
                    bc++;
                    break;
                }
                case IF_ICMPGE : {
                    fprintf(stderr, " if_icmpge ");
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
                case IF_ICMPLE : {
                    fprintf(stderr, " if_icmple ");
                    bc++;
                    break;
                }
                case IF_ACMPEQ : {
                    fprintf(stderr, " if_acmpeq ");
                    bc++;
                    break;
                }
                case IF_ACMPNE : {
                    fprintf(stderr, " if_acmpne ");
                    bc++;
                    break;
                }
                case GOTO: {
                    int tmp = (signed short) ((bc[1] << 8) | (bc)[2]);
                    bc += tmp;
                    break;
                }
                case JSR : {
                    fprintf(stderr, " jsr ");
                    bc++;
                    break;
                }
                case RET : {
                    fprintf(stderr, " ret ");
                    bc++;
                    break;
                }
                case TABLESWITCH : {
                    fprintf(stderr, " tableswitch ");
                    bc++;
                    break;
                }
                case LOOKUPSWITCH : {
                    fprintf(stderr, " lookupswitch ");
                    bc++;
                    break;
                }
                case IRETURN: {
                    printf("%d\n", *--operand_stack);
                    bc++;
                }
                case LRETURN : {
                    fprintf(stderr, " lreturn ");
                    bc++;
                    break;
                }
                case FRETURN : {
                    fprintf(stderr, " freturn ");
                    bc++;
                    break;
                }
                case DRETURN : {
                    fprintf(stderr, " dreturn ");
                    bc++;
                    break;
                }
                case ARETURN : {
                    fprintf(stderr, " areturn ");
                    bc++;
                    break;
                }
                case RETURN : {
                    frame_t *pf = env_pop(env);
                    free(pf);
                    bc++;
                    break;
                }
                case GETSTATIC : {
                    *operand_stack++ = (uintptr_t) NULL;
                    bc += 3;
                    break;
                }
                case PUTSTATIC : {
                    fprintf(stderr, " putstatic ");
                    bc++;
                    break;
                }
                case GETFIELD : {
                    fprintf(stderr, " getfield ");
                    bc++;
                    break;
                }
                case PUTFIELD : {
                    fprintf(stderr, " putfield ");
                    bc++;
                    break;
                }
                case INVOKEVIRTUAL : {
                    uintptr_t val = *--operand_stack;
                    uintptr_t out = *--operand_stack;
                    printf("%d\n", val);
                    bc += 3;
                    break;
                }
                case INVOKESPECIAL : {
                    fprintf(stderr, " invokespecial ");
                    bc++;
                    break;
                }
                case INVOKESTATIC : {
                    fprintf(stderr, " invokestatic ");
                    bc++;
                    break;
                }
                case INVOKEINTERFACE : {
                    fprintf(stderr, " invokeinterface ");
                    bc++;
                    break;
                }
                case INVOKEDYNAMIC : {
                    fprintf(stderr, " invokedynamic ");
                    bc++;
                    break;
                }
                case NEW : {
                    fprintf(stderr, " new ");
                    bc++;
                    break;
                }
                case NEWARRAY : {
                    fprintf(stderr, " newarray ");
                    bc++;
                    break;
                }
                case ANEWARRAY : {
                    fprintf(stderr, " anewarray ");
                    bc++;
                    break;
                }
                case ARRAYLENGTH : {
                    fprintf(stderr, " arraylength ");
                    bc++;
                    break;
                }
                case ATHROW : {
                    fprintf(stderr, " athrow ");
                    bc++;
                    break;
                }
                case CHECKCAST : {
                    fprintf(stderr, " checkcast ");
                    bc++;
                    break;
                }
                case INSTANCEOF : {
                    fprintf(stderr, " instanceof ");
                    bc++;
                    break;
                }
                case MONITORENTER : {
                    fprintf(stderr, " monitorenter ");
                    bc++;
                    break;
                }
                case MONITOREXIT : {
                    fprintf(stderr, " monitorexit ");
                    bc++;
                    break;
                }
                case WIDE : {
                    fprintf(stderr, " wide ");
                    bc++;
                    break;
                }
                case MULTIANEWARRAY : {
                    fprintf(stderr, " multianewarray ");
                    bc++;
                    break;
                }
                case IFNULL : {
                    fprintf(stderr, " ifnull ");
                    bc++;
                    break;
                }
                case IFNONNULL : {
                    fprintf(stderr, " ifnonnull ");
                    bc++;
                    break;
                }
                case GOTO_W : {
                    fprintf(stderr, " goto_w ");
                    bc++;
                    break;
                }
                case JSR_W : {
                    fprintf(stderr, " jsr_w ");
                    bc++;
                    break;
                }
                case BREAKPOINT : {
                    fprintf(stderr, " breakpoint ");
                    bc++;
                    break;
                }
                case IMPDEP1 : {
                    fprintf(stderr, " impdep1 ");
                    bc++;
                    break;
                }
                case IMPDEP2 : {
                    fprintf(stderr, " impdep2 ");
                    bc++;
                    break;
                }
                default : {
                    fprintf(stderr, ".......... %x \n", tag);
                    exit(-1);
                    break;
                }
            }
        }
    }

}

void execute_static_method(method_t *method) {
    // main frame
    frame_t *mf = frame_init(method);
    env_push(env, mf);

    // interpreter run...
    execute();
}
