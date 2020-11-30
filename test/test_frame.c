#include "../src/jvm.h"

#include "assert.h"

void test_frame_init() {
    method_t *method = &((method_t) {.flag = 1, .name = "test", .descriptor="Z", .max_stack=1, .max_locals=1});
    frame_t *f = frame_init(method);

    assert_eq_int(0, f->stat, "new frame stat is 0");
}

void test_env_init() {
    method_t *m1 = &((method_t) {.flag = 1, .name = "t1", .descriptor="Z", .max_stack=1, .max_locals=1});
    frame_t *f1 = frame_init(m1);
    method_t *m2 = &((method_t) {.flag = 1, .name = "t2", .descriptor="Z", .max_stack=1, .max_locals=1});
    frame_t *f2 = frame_init(m2);
    method_t *m3 = &((method_t) {.flag = 1, .name = "t3", .descriptor="Z", .max_stack=1, .max_locals=1});
    frame_t *f3 = frame_init(m3);

    env_t *env = env_init(2);
    assert_eq_int(0, env->top, "top is 0");
    assert_eq_int(2, env->size, "size is 2");

    env_push(env, f1);
    assert_eq_int(1, env->top, "top is 1");
    frame_t *tf = env_top_frame(env);
    assert_eq_ptr(f1, tf, NULL);
    frame_t *pf = env_pop(env);
    assert_eq_ptr(f1, pf, NULL);
    assert_eq_int(0, env->top, "top is 0");

    env_push(env, f1);
    env_push(env, f2);
    env_push(env, f3);
    assert_eq_int(CODE_ERR_STACK_OVERFLOW, env->code, "stack over flow");

    frame_t *p1 = env_pop(env);
    assert_eq_ptr(f2, p1, NULL);
    frame_t *p2 = env_pop(env);
    assert_eq_ptr(f1, p2, NULL);
    frame_t *nf = env_pop(env);
    assert_null(nf, "pop of empty env is NULL");
}

void test_frame() {
    println_string("Test frame ...");
    test_frame_init();
    test_env_init();
}
