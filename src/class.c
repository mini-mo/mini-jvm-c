#include "jvm.h"

method_t *find_special_method(class_t *cls, char *name, char *descriptor) {
    method_t *method = cls->methods;
    for (; NULL != method; method++) {
        if ((method->flag & 0x0008) && strcmp(method->name, name) == 0 && strcmp(method->descriptor, descriptor) == 0) {
            return method;
        }
    }
    return NULL;
}
