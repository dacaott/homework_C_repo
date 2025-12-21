add_library(SortedList sortedList.c)

add_executable(sortedList main.c)
target_link_libraries(sortedList PRIVATE SortedList)

add_executable(sortedListTest test.c)
target_link_libraries(sortedListTest PRIVATE SortedList)

target_compile_definitions(sortedListTest PRIVATE TEST)