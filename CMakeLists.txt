cmake_minimum_required(VERSION 3.15)
project(mini-jvm-c C)

enable_language(C ASM)

set(CMAKE_C_STANDARD 99)

find_package(ZLIB REQUIRED)
if (ZLIB_FOUND)
    message(STATUS "ZLIB FOUND ${ZLIB_INCLUDE_DIRS} ${ZLIB_LIBRARIES}")
endif (ZLIB_FOUND)

set(
        VM_SOURCES
        src/jvm.h
        src/hello.c
        src/reader.c
)

# main
add_library(vm ${VM_SOURCES})
add_executable(jvm src/main.c)
target_link_libraries(jvm vm z)


set(
        VM_TESTS_SOURCES
        test/test.h
        test/assert.h
        test/assert.c
        test/test_class_reader.c
)

## test
add_executable(test test/test.c ${VM_TESTS_SOURCES})
target_link_libraries(test vm z)

# copy files

file(COPY misc DESTINATION ${CMAKE_BINARY_DIR})
file(COPY tests DESTINATION ${CMAKE_BINARY_DIR})
