#include <stdio.h>

int main() {
  int sum = 0;
  int previous = 1;
  int current = 2;

  while (current <= 1000000) {
    if (current % 2 == 0)
      sum += current;

    int next = previous + current;
    previous = current;
    current = next;
  }

  printf("Сумма всех чётных чисел Фибоначчи, не превосходящих миллиона: %d\n",
         sum);
  return 0;
}