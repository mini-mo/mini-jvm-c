#include "jvm.h"

meta_space_t *meta_space_init() {
    meta_space_t *ms = malloc(sizeof(meta_space_t));
    return ms;
}

void set_main_env(meta_space_t *meta, env_t *env) {
    meta->env = env;
}

env_t *main_env(meta_space_t *meta) {
    return meta->env;
}
