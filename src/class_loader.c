#include "jvm.h"

// load class from classpath

// 构造函数
class_loader_t *class_loader_init(char cp[]) {
    // unix separator :
    char *cps = strdup(cp);
    int cnt = 1;
    int cp_len = 0;
    for (; *cps != '\0'; cps++) {
        if (*cps == ':') {
            cnt++;
        }
        cp_len++;
    }
    cps -= cp_len;
    free(cps);

    char **paths = malloc(sizeof(char *) * cnt);
    char *cps2 = strdup(cp);
    int pi = 0;
    int si = 0;
    int ei = 0;
    for (int i = 0; i < cp_len; ++i) {
        if (cps2[i] == ':') {
            int tl = sizeof(char) * (ei - si);
            char *tmp = malloc(tl + 1);
            tmp[tl] = '\0';
            for (int j = si; j < ei; ++j) {
                tmp[j - si] = cp[j];
            }
            paths[pi] = tmp;
            pi++;
            si = ei + 1;
        }
        ei++;
    }

    int tl = sizeof(char) * (ei - si);
    char *tmp = malloc(tl + 1);
    tmp[tl] = '\0';
    for (int j = si; j < ei; ++j) {
        tmp[j - si] = cp[j];
    }
    paths[pi] = tmp;

    free(cps2);

    class_loader_t *cl = malloc(sizeof(class_loader_t));
    cl->cnt = 2;
    cl->paths = paths;
    return cl;
}

class_t *load_class(class_loader_t *cl, const char *name) {
    class_file_t *cf = NULL;
    for (int i = 0; i < cl->cnt; ++i) {
        char *cp = cl->paths[i];
        // end with jar
        size_t len = strlen(cp);
        if (len > 4 && cp[len - 4] == '.' && cp[len - 3] == 'j' && cp[len - 2] == 'a' && cp[len - 1] == 'r') {
            // TODO find class_file_t from jar
            println_string("(WIP) load class from jar");
            cf = read_class_from_jar(cp, name);
        } else {
            cf = read_class_from_dir(cp, name);
        }

        if (cf == NULL) {
            continue;
        }

        class_t *cls = malloc(sizeof(class_t));
        cls->cf = cf;
        cls->methods = NULL;
        cls->fields = NULL;
        cls->stat = CLASS_LOADED;
        return cls;
    }
    return NULL;
}

void class_loader_destroy(class_loader_t *cl) {
    free(cl->paths);
    free(cl);
}

