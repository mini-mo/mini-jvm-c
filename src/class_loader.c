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

class_t *define_class(class_file_t *cf);

void link_class(class_t *cls);

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

        class_t *cls = define_class(cf);
        link_class(cls);
        return cls;
    }
    return NULL;
}

class_t *define_class(class_file_t *cf) {
    class_t *cls = malloc(sizeof(class_t));
    cls->cf = cf;
    cp_info_t *cp = cf->constant_pool;

    cls->methods = malloc(sizeof(method_t) * cf->methods_count);
    for (int i = 0; i < cf->methods_count; ++i) {
        method_info_t mi = cf->methods[i];
        method_t *m = &(cls->methods[i]);
        m->name = (char *) cp[mi.name_index].info;
        m->descriptor = (char *) cp[mi.descriptor_index].info;
        m->flag = mi.access_flags;

        for (int j = 0; j < mi.attributes_count; ++j) {
            attribute_info_t info = mi.attributes[j];
            u2 ni = info.attribute_name_index;
            cp_info_t cpi = cp[ni];
            if (cpi.tag != CONSTANT_Utf8) {
                continue;
            }
            if (strcmp((char *) cpi.info, "Code") != 0) {
                continue;
            }

            u1 *bytes = info.body;
            m->max_stack = (bytes[0] << 8) | bytes[1];
            bytes += 2;
            m->max_locals = (bytes[0] << 8) | bytes[1];
            bytes += 2;
            int code_length = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
            bytes += 4;
            m->bc = malloc(sizeof(u1) * code_length);
            memcpy(m->bc, bytes, code_length);
            break;
        };
    }

    cls->fields = NULL;
    cls->stat = CLASS_LOADED;
    return cls;
}

void link_class(class_t *cls) {

}

void class_loader_destroy(class_loader_t *cl) {
    free(cl->paths);
    free(cl);
}

