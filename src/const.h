#ifndef MINI_JVM_C_CONST_H
#define MINI_JVM_C_CONST_H

// boolean
#define TRUE 1
#define FALSE 0

// constant pool
#define CONSTANT_Class    7
#define CONSTANT_Fieldref    9
#define CONSTANT_Methodref    10
#define CONSTANT_InterfaceMethodref    11
#define CONSTANT_String    8
#define CONSTANT_Integer    3
#define CONSTANT_Float    4
#define CONSTANT_Long    5
#define CONSTANT_Double    6
#define CONSTANT_NameAndType    12
#define CONSTANT_Utf8    1
#define CONSTANT_MethodHandle    15
#define CONSTANT_MethodType    16
#define CONSTANT_InvokeDynamic    18

// class
#define CLASS_LOADED  1
#define CLASS_LINKED  2
#define CLASS_INITIALING  3
#define CLASS_INITIALIZED 4


// opcode
#define NOP 0x00 // 00
#define ACONST_NULL 0x01 // 01
#define ICONST_M1 0x02 // 02
#define ICONST_0 0x03 // 03
#define ICONST_1 0x04 // 04
#define ICONST_2 0x05 // 05
#define ICONST_3 0x06 // 06
#define ICONST_4 0x07 // 07
#define ICONST_5 0x08 // 08
#define LCONST_0 0x09 // 09
#define LCONST_1 0x0a // 10
#define FCONST_0 0x0b // 11
#define FCONST_1 0x0c // 12
#define FCONST_2 0x0d // 13
#define DCONST_0 0x0e // 14
#define DCONST_1 0x0f // 15
#define BIPUSH 0x10 // 16
#define SIPUSH 0x11 // 17
#define LDC 0x12 // 18
#define LDC_W 0x13 // 19
#define LDC2_W 0x14 // 20
#define ILOAD 0x15 // 21
#define LLOAD 0x16 // 22
#define FLOAD 0x17 // 23
#define DLOAD 0x18 // 24
#define ALOAD 0x19 // 25
#define ILOAD_0 0x1a // 26
#define ILOAD_1 0x1b // 27
#define ILOAD_2 0x1c // 28
#define ILOAD_3 0x1d // 29
#define LLOAD_0 0x1e // 30
#define LLOAD_1 0x1f // 31
#define LLOAD_2 0x20 // 32
#define LLOAD_3 0x21 // 33
#define FLOAD_0 0x22 // 34
#define FLOAD_1 0x23 // 35
#define FLOAD_2 0x24 // 36
#define FLOAD_3 0x25 // 37
#define DLOAD_0 0x26 // 38
#define DLOAD_1 0x27 // 39
#define DLOAD_2 0x28 // 40
#define DLOAD_3 0x29 // 41
#define ALOAD_0 0x2a // 42
#define ALOAD_1 0x2b // 43
#define ALOAD_2 0x2c // 44
#define ALOAD_3 0x2d // 45
#define IALOAD 0x2e // 46
#define LALOAD 0x2f // 47
#define FALOAD 0x30 // 48
#define DALOAD 0x31 // 49
#define AALOAD 0x32 // 50
#define BALOAD 0x33 // 51
#define CALOAD 0x34 // 52
#define SALOAD 0x35 // 53
#define ISTORE 0x36 // 54
#define LSTORE 0x37 // 55
#define FSTORE 0x38 // 56
#define DSTORE 0x39 // 57
#define ASTORE 0x3a // 58
#define ISTORE_0 0x3b // 59
#define ISTORE_1 0x3c // 60
#define ISTORE_2 0x3d // 61
#define ISTORE_3 0x3e // 62
#define LSTORE_0 0x3f // 63
#define LSTORE_1 0x40 // 64
#define LSTORE_2 0x41 // 65
#define LSTORE_3 0x42 // 66
#define FSTORE_0 0x43 // 67
#define FSTORE_1 0x44 // 68
#define FSTORE_2 0x45 // 69
#define FSTORE_3 0x46 // 70
#define DSTORE_0 0x47 // 71
#define DSTORE_1 0x48 // 72
#define DSTORE_2 0x49 // 73
#define DSTORE_3 0x4a // 74
#define ASTORE_0 0x4b // 75
#define ASTORE_1 0x4c // 76
#define ASTORE_2 0x4d // 77
#define ASTORE_3 0x4e // 78
#define IASTORE 0x4f // 79
#define LASTORE 0x50 // 80
#define FASTORE 0x51 // 81
#define DASTORE 0x52 // 82
#define AASTORE 0x53 // 83
#define BASTORE 0x54 // 84
#define CASTORE 0x55 // 85
#define SASTORE 0x56 // 86
#define POP 0x57 // 87
#define POP2 0x58 // 88
#define DUP 0x59 // 89
#define DUP_X1 0x5a // 90
#define DUP_X2 0x5b // 91
#define DUP2 0x5c // 92
#define DUP2_X1 0x5d // 93
#define DUP2_X2 0x5e // 94
#define SWAP 0x5f // 95
#define IADD 0x60 // 96
#define LADD 0x61 // 97
#define FADD 0x62 // 98
#define DADD 0x63 // 99
#define ISUB 0x64 // 100
#define LSUB 0x65 // 101
#define FSUB 0x66 // 102
#define DSUB 0x67 // 103
#define IMUL 0x68 // 104
#define LMUL 0x69 // 105
#define FMUL 0x6a // 106
#define DMUL 0x6b // 107
#define IDIV 0x6c // 108
#define LDIV 0x6d // 109
#define FDIV 0x6e // 110
#define DDIV 0x6f // 111
#define IREM 0x70 // 112
#define LREM 0x71 // 113
#define FREM 0x72 // 114
#define DREM 0x73 // 115
#define INEG 0x74 // 116
#define LNEG 0x75 // 117
#define FNEG 0x76 // 118
#define DNEG 0x77 // 119
#define ISHL 0x78 // 120
#define LSHL 0x79 // 121
#define ISHR 0x7a // 122
#define LSHR 0x7b // 123
#define IUSHR 0x7c // 124
#define LUSHR 0x7d // 125
#define IAND 0x7e // 126
#define LAND 0x7f // 127
#define IOR 0x80 // 128
#define LOR 0x81 // 129
#define IXOR 0x82 // 130
#define LXOR 0x83 // 131
#define IINC 0x84 // 132
#define I2L 0x85 // 133
#define I2F 0x86 // 134
#define I2D 0x87 // 135
#define L2I 0x88 // 136
#define L2F 0x89 // 137
#define L2D 0x8a // 138
#define F2I 0x8b // 139
#define F2L 0x8c // 140
#define F2D 0x8d // 141
#define D2I 0x8e // 142
#define D2L 0x8f // 143
#define D2F 0x90 // 144
#define I2B 0x91 // 145
#define I2C 0x92 // 146
#define I2S 0x93 // 147
#define LCMP 0x94 // 148
#define FCMPL 0x95 // 149
#define FCMPG 0x96 // 150
#define DCMPL 0x97 // 151
#define DCMPG 0x98 // 152
#define IFEQ 0x99 // 153
#define IFNE 0x9a // 154
#define IFLT 0x9b // 155
#define IFGE 0x9c // 156
#define IFGT 0x9d // 157
#define IFLE 0x9e // 158
#define IF_ICMPEQ 0x9f // 159
#define IF_ICMPNE 0xa0 // 160
#define IF_ICMPLT 0xa1 // 161
#define IF_ICMPGE 0xa2 // 162
#define IF_ICMPGT 0xa3 // 163 3
#define IF_ICMPLE 0xa4 // 164
#define IF_ACMPEQ 0xa5 // 165
#define IF_ACMPNE 0xa6 // 166
#define GOTO 0xa7 // 167
#define JSR 0xa8 // 168
#define RET 0xa9 // 169
#define TABLESWITCH 0xaa // 170
#define LOOKUPSWITCH 0xab // 171
#define IRETURN 0xac // 172
#define LRETURN 0xad // 173
#define FRETURN 0xae // 174
#define DRETURN 0xaf // 175
#define ARETURN 0xb0 // 176
#define RETURN 0xb1 // 177
#define GETSTATIC 0xb2 // 178
#define PUTSTATIC 0xb3 // 179
#define GETFIELD 0xb4 // 180
#define PUTFIELD 0xb5 // 181
#define INVOKEVIRTUAL 0xb6 // 182
#define INVOKESPECIAL 0xb7 // 183
#define INVOKESTATIC 0xb8 // 184
#define INVOKEINTERFACE 0xb9 // 185
#define INVOKEDYNAMIC 0xba // 186
#define NEW 0xbb // 187
#define NEWARRAY 0xbc // 188
#define ANEWARRAY 0xbd // 189
#define ARRAYLENGTH 0xbe // 190
#define ATHROW 0xbf // 191
#define CHECKCAST 0xc0 // 192
#define INSTANCEOF 0xc1 // 193
#define MONITORENTER 0xc2 // 194
#define MONITOREXIT 0xc3 // 195
#define WIDE 0xc4 // 196
#define MULTIANEWARRAY 0xc5 // 197
#define IFNULL 0xc6 // 198
#define IFNONNULL 0xc7 // 199
#define GOTO_W 0xc8 // 200
#define JSR_W 0xc9 // 201
#define BREAKPOINT 0xca // 202
#define IMPDEP1 0xfe // 254
#define IMPDEP2 0xff // 255

#define CODE_ERR_STACK_OVERFLOW 400001

#endif //MINI_JVM_C_CONST_H
