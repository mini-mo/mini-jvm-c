#include <stdio.h>
#include "jvm.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("must provide class path");
        return -1;
    }

    FILE *cls_file = fopen(argv[1], "r");
    assert(cls_file && "failed to open file");

    class_file *cf = read_class_file(cls_file);
    printf("magic: %x\n", cf->magic);

    fclose(cls_file);
    return 0;
}