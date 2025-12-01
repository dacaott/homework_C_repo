cmake_minimum_required(VERSION 3.25)

project(zadanieNumberX homework_C_repo)

add_library(compareBinary compareBinary.c)

add_executable(binaryNumberSystemComparison main.c)
target_link_libraries(binaryNumberSystemComparison compareBinary)

add_executable(binaryNumberSystemComparison_test test.c)
target_link_libraries(zadanieNumberX_test compareBinary)

target_compile_options(binaryNumberSystemComparison PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(binaryNumberSystemComparison_test PRIVATE -Wall -Wextra -Wpedantic)


