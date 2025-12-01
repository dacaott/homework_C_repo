cmake_minimum_required(VERSION 3.25)
project(homework_C_repo C)


file(GLOB_RECURSE CMAKE_LISTS "src/*/CMakeLists.txt")
foreach(CMAKE_LIST ${CMAKE_LISTS})
    get_filename_component(SUBDIR ${CMAKE_LIST} DIRECTORY)
    message(STATUS "Adding subdirectory: ${SUBDIR}")
    add_subdirectory(${SUBDIR})
endforeach()


add_compile_options(-Wall -Wextra -Wpedantic)