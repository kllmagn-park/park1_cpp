cmake_minimum_required(VERSION 3.12)
project(C_DZ1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage)

add_library(max_triang STATIC max_triang.c)
add_library(tools STATIC tools.c)

add_executable(main main.c)
target_link_libraries(main tools max_triang)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(max_triang_test max_triang_test.cpp)
target_link_libraries(max_triang_test ${GTEST_LIBRARIES} tools max_triang pthread)