#include <stdio.h>

int main()
{
    int triplet_count[28] = {0};  // количество троек цифр с каждой суммой (0…27)
    int first = 0;
    int second = 0;
    int third = 0;
    int sum = 0;
    int triples = 0;
    int luckyTickets = 0;

    printf("Введите сумму цифр (от 0 до 27): ");
    scanf("%d", &sum);

    if (sum < 0 || sum > 27) {
        printf("Некорректный ввод.\n");
        return 1;
    }

    for (first = 0; first <= 9; first++) {
        for (second = 0; second <= 9; second++) {
            for (third = 0; third <= 9; third++) {
                int s = first + second + third;
                triplet_count[s] = triplet_count[s] + 1;
            }
        }
    }

    triples = triplet_count[sum];

    luckyTickets = triples * triples;

    printf("Количество счастливых билетов = %d\n", luckyTickets);

    return 0;
}
// #include <stdio.h>

// int main() {
//     int sum;
//     int count = 0;

//     printf("Сумма цифр (от 0 до 27): ");
//     scanf("%d", &sum);

//     for (int a = 0; a <= 9; a++) {
//         for (int b = 0; b <= 9; b++) {
//             for (int c = 0; c <= 9; c++) {
//                 int s1 = a + b + c;  
//                 if (s1 != sum) continue; 

//                 for (int d = 0; d <= 9; d++) {
//                     for (int e = 0; e <= 9; e++) {
//                         for (int f = 0; f <= 9; f++) {
//                             int s2 = d + e + f; 
//                             if (s2 == sum) {
//                                 count++;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     printf("Количество счастливых билетов = %d\n", count);

//     return 0;
// }