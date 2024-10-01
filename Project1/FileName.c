#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int index_first_even(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            return i;
        }
    }
    return -1;
}

int index_last_odd(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] % 2 != 0) {
            return i;
        }
    }
    return -1;
}

int sum_between_even_odd(int arr[], int size, int first_even, int last_odd) {
    int sum = 0;
    for (int i = first_even; i < last_odd; i++) {
        sum += abs(arr[i]);
    }
    return sum;
}

int sum_before_even_and_after_odd(int arr[], int size, int first_even, int last_odd) {
    int sum = 0;
    for (int i = 0; i < first_even; i++) {
        sum += abs(arr[i]);
    }
    for (int i = last_odd; i < size; i++) {
        sum += abs(arr[i]);
    }
    return sum;
}

int main() {
    int string;
    scanf("%d", &string);

    int arr[100];
    int size = 0;
    char c;

    while (scanf("%d%c", &arr[size], &c) == 2) {
        size++;
        if (c == '\n') {
            break;
        }
    }

    int first_even = index_first_even(arr, size);
    int last_odd = index_last_odd(arr, size);

    switch (string) {
    case 0:
        printf("%d\n", first_even);
        break;
    case 1:
        printf("%d\n", last_odd);
        break;
    case 2:
        printf("%d\n", sum_between_even_odd(arr, size, first_even, last_odd));
        break;
    case 3:
        printf("%d\n", sum_before_even_and_after_odd(arr, size, first_even, last_odd));
        break;
    default:
        printf("Данные некорректны\n");
        break;
    }

    return 0;
}
