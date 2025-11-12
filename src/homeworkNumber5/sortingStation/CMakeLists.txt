add_library(stack stack.c)

add_executable(sortingStation sortingStation.c)

target_link_libraries(sortingStation PRIVATE stack)
