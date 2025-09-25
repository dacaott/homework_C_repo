#include <stdio.h>

void reverse_segment(int *array, int start_index, int end_index) {
    while (start_index < end_index) {
        int temp = array[start_index];
        array[start_index] = array[end_index];
        array[end_index] = temp;
        start_index++;
        end_index--;
    }
}

void swap_two_segments(int *array, int first_segment_length, int second_segment_length) {
    int total_length = first_segment_length + second_segment_length;
    reverse_segment(array, 0, first_segment_length - 1);
    reverse_segment(array, first_segment_length, total_length - 1);
    reverse_segment(array, 0, total_length - 1);
}

int main() {
    int first_segment_length, second_segment_length;

    printf("Введите длину первого сегмента массива (m): ");
    scanf("%d", &first_segment_length);

    printf("Введите длину второго сегмента массива (n): ");
    scanf("%d", &second_segment_length);

    int total_length = first_segment_length + second_segment_length;
    int input_array[total_length];

    printf("Введите %d целых чисел массива через пробел:\n", total_length);
    for (int i = 0; i < total_length; ++i) {
        scanf("%d", &input_array[i]);
    }

    swap_two_segments(input_array, first_segment_length, second_segment_length);

    printf("Полученный массив:\n");
    for (int i = 0; i < total_length; ++i) {
        printf("%d ", input_array[i]);
    }
    printf("\n");

    return 0;
}