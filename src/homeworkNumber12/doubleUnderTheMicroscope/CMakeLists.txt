add_library(double_lib double.c)

add_executable(main main.c)
target_link_libraries(main double_lib)

add_executable(tests test.c)
target_link_libraries(tests double_lib)