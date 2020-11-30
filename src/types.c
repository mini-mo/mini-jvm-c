#include "jvm.h"

// frame

frame_t *frame_init(method_t *method) {
    frame_t *f = malloc(sizeof(frame_t));
    f->method = method;
    f->local_vars = malloc(sizeof(uintptr_t) * method->max_locals);
    f->operand_stack = malloc(sizeof(uintptr_t) * method->max_stack);
    f->stat = 0;
    return f;
}

// env
env_t *env_init(int size) {
    env_t *env = malloc(sizeof(env_t));
    env->size = size;
    env->top = 0;
    env->frame = malloc(sizeof(frame_t *) * size);
    return env;
}

void env_destroy(env_t *env) {
    // TODO
}

frame_t *env_top_frame(env_t *env) {
    if (env_empty(env)) {
        return NULL;
    }
    return env->frame[env->top - 1];
}

void env_push(env_t *env, frame_t *frame) {
    if (env->top == env->size) {
        env->code = CODE_ERR_STACK_OVERFLOW;
        return;
    }
    env->frame[env->top] = frame;
    env->top++;
}

frame_t *env_pop(env_t *env) {
    frame_t *top = env_top_frame(env);
    if (top == NULL) {
        return NULL;
    }
    env->top--;
    return top;
}

int env_empty(env_t *env) {
    return env->top == 0 ? TRUE : FALSE;
}
