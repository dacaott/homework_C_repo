#include <stdio.h>

int main()
{
    int tripletCount[28] = { 0 }; // количество троек цифр с каждой суммой (0…27)
    int luckyTickets = 0;

    for (int first = 0; first <= 9; first++) {
        for (int second = 0; second <= 9; second++) {
            for (int third = 0; third <= 9; third++) {
                int s = first + second + third;
                tripletCount[s]++;
            }
        }
    }

    // суммируем квадраты
    for (int s = 0; s <= 27; s++) {
        luckyTickets += tripletCount[s] * tripletCount[s];
    }
    printf("Общее количество счастливых билетов = %d\n", luckyTickets);

    return 0;
}