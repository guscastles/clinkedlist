cmake_minimum_required(VERSION 3.13)
project(linkedlist LANGUAGES C)
include_directories(include)
add_definitions("-g")
add_executable(main src/main.c)

enable_testing()
add_executable(test_list test/test.c src/llist.c)
add_test(test_list ${EXECUTABLE_OUTPUT_PATH}/test_list)
