#include "../src/jvm.h"
#include "assert.h"

void test_class_loader_init() {
    char cp[] = "misc:jre";
    class_loader_t *cl = class_loader_init(cp);

    assert_eq_int(2, cl->cnt, "misc:jre -> 2");
    assert_eq_string("misc", cl->paths[0], "misc:jre -> misc");
    assert_eq_string("jre", cl->paths[1], "misc:jre -> jre");
}

void test_class_loader_misc_test() {
    char cp[] = "misc:jre";
    class_loader_t *cl = class_loader_init(cp);

    class_t *cls = load_class(cl, "Test");
    class_t *obj = load_class(cl, "java/lang/Object");
    assert_not_null(cls, "Test class found");
    assert_not_null(obj, "java/lang/Object class found");
}

void test_class_loader() {
    println_string("Test class loader ...");
    test_class_loader_init();
    test_class_loader_misc_test();
    println();
}
