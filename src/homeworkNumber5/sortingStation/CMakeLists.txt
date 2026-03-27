add_library(stack ../stack.c)

target_include_directories(stack PUBLIC ..)

add_executable(sortingStation sortingStation.c)

target_include_directories(sortingStation PRIVATE ..) 

target_link_libraries(sortingStation PRIVATE stack)