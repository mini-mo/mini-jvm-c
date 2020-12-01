#include "jvm.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        println_string("must provide class path");
        return -1;
    }

    // FIXME user parameters
    class_loader_t *cl = class_loader_init("misc:jre");

    char *main_class = strdup(argv[1]);
    char *cpntr;
    for (cpntr = main_class; *cpntr; cpntr++) {
        if (*cpntr == '.') {
            *cpntr = '/';
        }
    }

    class_t *cls = load_class(cl, main_class);
    method_t *mm = find_special_method(cls, "test", "()I");

    // vm init
    env = env_init(10);

    // main frame
    frame_t *mf = frame_init(mm);
    env_push(env, mf);

    // interpreter run...
    execute();

    return 0;
}
