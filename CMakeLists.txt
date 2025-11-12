cmake_minimum_required(VERSION 3.25)
project(homework_C_repo C)


file(GLOB SUBDIRECTORIES LIST_DIRECTORIES true "src/*")
foreach(SUBDIR ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${SUBDIR} AND EXISTS "${SUBDIR}/CMakeLists.txt")
        message(STATUS "Adding subdirectory: ${SUBDIR}")
        add_subdirectory(${SUBDIR})
    endif()
endforeach()

add_compile_options(-Wall -Wextra -Wpedantic)
