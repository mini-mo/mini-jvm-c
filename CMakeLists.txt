cmake_minimum_required(VERSION 3.15)
project(mini-jvm-c C)

enable_language(C ASM)

set(CMAKE_C_STANDARD 99)

set(
        VM_SOURCES
        src/const.h
        src/jvm.h
        src/utils.c
        src/hello.c
        src/reader.c
        src/class_loader.c
        src/meta_space.c
        src/types.c
        src/class.c
)

# main
add_library(vm ${VM_SOURCES})
add_executable(jvm src/main.c)
target_link_libraries(jvm vm)


set(
        VM_TESTS_SOURCES
        test/test.h
        test/assert.h
        test/assert.c
        test/test_class_reader.c
        test/test_class_loader.c
        test/test_frame.c
)

## test
add_executable(test test/test.c ${VM_TESTS_SOURCES})
target_link_libraries(test vm)

# copy files
file(COPY misc DESTINATION ${CMAKE_BINARY_DIR})
file(COPY tests DESTINATION ${CMAKE_BINARY_DIR})
file(COPY jre DESTINATION ${CMAKE_BINARY_DIR})
