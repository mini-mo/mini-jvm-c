#include <stdio.h>
#include <stdlib.h>

void pass(char *msg) {
    if (msg) {
        printf("Running test, %s... \033[0;32mPassed\033[0m\n", msg);
    }
}

void un_pass(char *msg) {
    if (msg) {
        printf("Running test, %s... \033[0;31mPassed\033[0m\n", msg);
    }
}

void assert_eq_int(int expect, int actual, char *msg) {
    if (actual == expect) {
        if (msg) {
            pass(msg);
        }
        return;
    }
    un_pass(msg);
    exit(-1);
}
