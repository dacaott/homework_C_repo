#include <stdio.h>

int main() {
  int tripletCount[28] = {0}; // количество троек цифр с каждой суммой (0…27)
  int sum = 0;
  int triples = 0;
  int luckyTickets = 0;

  printf("Введите сумму цифр (от 0 до 27): ");
  scanf("%d", &sum);

  if (sum < 0 || sum > 27) {
    printf("Некорректный ввод.\n");
    return 1;
  }

  for (int first = 0; first <= 9; first++) {
    for (int second = 0; second <= 9; second++) {
      for (int third = 0; third <= 9; third++) {
        int s = first + second + third;
        tripletCount[s]++;
      }
    }
  }

  triples = tripletCount[sum];

  luckyTickets = triples * triples;

  printf("Количество счастливых билетов = %d\n", luckyTickets);

  return 0;
}
