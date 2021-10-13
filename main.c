#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#include "./max_triang.h"

static int input_arr(float *arr, const int n, char name) {
    printf("Элементы массива %c (разделенные пробелом и/или новой строкой): "
           , name);
    for (int i = 0; i < n; i++) {
        if (scanf("%f", &arr[i]) != 1) {
            printf("Ошибка; неправильный формат ввода.");
            return 1;
        } else if (arr[i] >= FLT_MAX || arr[i] <= FLT_MIN) {
            printf("Ошибка: значение выходит за допустимые пределы.");
            return 1;
        }
    }
    return 0;
}

int main() {
        printf("Введите количество точек (n): ");
        int n = 0;
        if (scanf("%d", &n) != 1) {
            printf("Ошибка; неправильный формат ввода.");
            return 1;
        } else if (n < 4) {
            printf("Ошибка: количество точек выходит за доступные границы.");
            return 1;
        }

        float X[n];
        if (input_arr(X, n, 'X'))
            return 1;
        float Y[n];
        if (input_arr(Y, n, 'Y'))
            return 1;
        const float **pX = arr_to_parr(X, n);
        const float **pY = arr_to_parr(Y, n);
        const int** inds = max_triang(pX, pY, n);
        free(pX);
        free(pY);
        if (inds != NULL)
            printf("Номера точек: %d %d %d\n", *inds[0], *inds[1], *inds[2]);
        else
            printf("Точки не найдены.");
        return 0;
}
