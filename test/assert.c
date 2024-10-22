#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pass(const char *msg) {
    if (msg) {
        printf("Running test, %s ... \033[0;32mPassed\033[0m\n", msg);
    }
}

void un_pass(const char *msg) {
    if (msg) {
        printf("Running test, %s ... \033[0;31mFailure\033[0m\n", msg);
    } else {
        printf("Running test, ... \033[0;31mFailure\033[0m\n");
    }
}

void assert_eq_int(int expect, int actual, const char *msg) {
    if (actual == expect) {
        pass(msg);
        return;
    }
    un_pass(msg);
    exit(-1);
}

void assert_eq_string(const char *expect, const char *actual, const char *msg) {
    if (strcmp(expect, actual) == 0) {
        pass(msg);
        return;
    }
    un_pass(msg);
    exit(-1);
}

void assert_null(void *obj, const char *msg) {
    if (obj == NULL) {
        pass(msg);
        return;
    }
    un_pass(msg);
    exit(-1);
}

void assert_not_null(void *obj, const char *msg) {
    if (obj != NULL) {
        pass(msg);
        return;
    }
    un_pass(msg);
    exit(-1);
}

void assert_eq_ptr(void *expect, void *actual, const char *msg) {
    if (expect == actual) {
        pass(msg);
        return;
    }
    un_pass(msg);
    exit(-1);
}
