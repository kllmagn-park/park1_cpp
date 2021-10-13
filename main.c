#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#include "./max_triang.h"

static int input_arr(float *arr, int n, char name) {
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

int memerr() {
    perror("Критическая ошибка");
    return 1;
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
        float *X = (float*)malloc(sizeof(float)*n);
        if (X == NULL) {
            return memerr();
        }
        if (input_arr(X, n, 'X'))
            return 1;
        float *Y = (float*)malloc(sizeof(float)*n);
        if (Y == NULL) {
            free(X);
            return memerr();
        }
        if (input_arr(Y, n, 'Y'))
            return 1;
        const float **pX = arr_to_parr(X, n);
        if (pX == NULL) {
            free(X);
            free(Y);
            return memerr();
        }
        const float **pY = arr_to_parr(Y, n);
        if (pY == NULL) {
            freep((void**)pX, n);
            return memerr();
        }
        const int** inds = max_triang(pX, pY, n);
        freep((void**)pX, n);
        freep((void**)pY, n);
        if (inds != NULL)
            printf("Номера точек: %d %d %d\n", *inds[0], *inds[1], *inds[2]);
        else
            printf("Точки не найдены.");
        freep((void**)inds, 3);
        return 0;
}
