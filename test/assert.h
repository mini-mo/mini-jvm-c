#ifndef MINI_JVM_C_ASSERT_H
#define MINI_JVM_C_ASSERT_H

void assert_eq_int(int expect, int actual, const char *msg);

void assert_eq_string(const char *expect, const char *actual, const char *msg);

void assert_not_null(void *obj, const char *msg);

#endif //MINI_JVM_C_ASSERT_H
