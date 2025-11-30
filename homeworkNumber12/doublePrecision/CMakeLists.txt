cmake_minimum_required(VERSION 3.25)
project(homeworkNumber5 homework_C_repo)

# основная программа
add_executable(main main.c double.c)

# тесты
add_executable(tests test.c double.c)