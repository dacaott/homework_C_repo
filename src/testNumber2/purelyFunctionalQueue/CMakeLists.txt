cmake_minimum_required(VERSION 3.25)

project(purelyFunctionalQueue homework_C_repo)

add_library(queue
    queue.c
    list.c
)

target_include_directories(queue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testQueue test.c)
target_link_libraries(testQueue queue)

add_compile_options(-Wall -Wextra -Wpedantic)