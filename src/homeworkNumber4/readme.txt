Файлы проекта:
- optimalSorting.c   — программа на C
- sort.c             — функция bubble_sort
- sort.s             — ассемблерный файл, сгенерированный из sort.c
- sort.h             — заголовочный файл
- readme.txt         — инструкция по сборке и запуску



Как собрать:

1. 
   gcc -Wall -Wextra -pedantic -S -O2 sort.c -o sort.s

2. 
   gcc -Wall -Wextra -pedantic optimalSorting.c -c

3. 
   gcc -Wall -Wextra -pedantic optimalSorting.o sort.s -o optimalSorting

