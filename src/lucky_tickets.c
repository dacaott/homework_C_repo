#include <stdio.h>

int main() {
    int sum;
    int count = 0;

    printf("Сумма цифр (от 0 до 27): ");
    scanf("%d", &sum);

    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                int s1 = a + b + c;  
                if (s1 != sum) continue; 

                for (int d = 0; d <= 9; d++) {
                    for (int e = 0; e <= 9; e++) {
                        for (int f = 0; f <= 9; f++) {
                            int s2 = d + e + f; 
                            if (s2 == sum) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Количество счастливых билетов = %d\n", count);

    return 0;
}