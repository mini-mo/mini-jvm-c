#include "../src/jvm.h"

#include "assert.h"

void test_read() {
    FILE *file = fopen("misc/HelloWorld.class", "r");
    class_file *cf = read_class_file(file);
    assert_eq_int(0xcafebabe, cf->magic, "magic is 0xcafebabe");
    assert_eq_int(52, cf->major_version, "major_version is 52");
    assert_eq_int(29, cf->constant_pool_count, "constant_pool_count is 15");
    assert_eq_int(2, cf->methods_count, "methods count is 2");
    assert_eq_int(1, cf->attributes_count, "attributes count is 1");
}