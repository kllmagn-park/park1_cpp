#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#include "./tools.h"
#include "./max_triang.h"

static int memerr() {
    perror("Критическая ошибка");
    return 1;
}

static int input_arr(float **arr, int n, char name) {
    printf("Элементы массива %c (разделенные пробелом и/или новой строкой): "
           , name);
    for (int i = 0; i < n; i++) {
        float *x = malloc(sizeof(float));
        if (x == NULL) {
            return memerr();
        }
        if (scanf("%f", x) != 1) {
            printf("Ошибка; неправильный формат ввода.");
            free(x);
            return 1;
        } else if (*x >= FLT_MAX || *x <= FLT_MIN) {
            printf("Ошибка: значение выходит за допустимые пределы.");
            free(x);
            return 1;
        }
        arr[i] = x;
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
        float **X = (float**)malloc(sizeof(float*)*n);
        if (X == NULL) {
            return memerr();
        }
        if (input_arr(X, n, 'X')) {
            freep((void**)X, n);
            return 1;
        }
        float **Y = (float**)malloc(sizeof(float*)*n);
        if (Y == NULL) {
            freep((void**)X, n);
            return memerr();
        }
        if (input_arr(Y, n, 'Y')) {
            freep((void**)X, n);
            freep((void**)Y, n);
            return 1;
        }
        const int** inds = max_triang((const float**)X, (const float**)Y, n);
        freep((void**)X, n);
        freep((void**)Y, n);
        if (inds != NULL)
            printf("Номера точек: %d %d %d\n", *inds[0], *inds[1], *inds[2]);
        else
            printf("Точки не найдены.");
        freep((void**)inds, 3);
        return 0;
}
