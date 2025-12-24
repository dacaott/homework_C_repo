add_library(stack ../stack.c)

target_include_directories(stack PUBLIC ..)

add_executable(advancedBracketBalance advancedBracketBalance.c)

target_include_directories(advancedBracketBalance PRIVATE ..)

target_link_libraries(advancedBracketBalance PRIVATE stack)