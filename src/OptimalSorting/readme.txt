Файлы проекта:
- main.c     — программа на C
- sort.c     — функция bubble_sort
- sort.s     — ассемблерный файл, сгенерированный из bubble.c
- readme.txt — инструкция по сборке и запуску



Как собрать:

1. Сначала создаём sort.s из bubble.c:
   gcc -O0 -S sort.c -o sort.s

2. Затем собираем проект:
   gcc -no-pie -o sort main.c sort.s


Как запускать:
./sort
