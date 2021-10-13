#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#include "max_triang.h"

enum { INPUT_SIZE = 30 };
char *ptr;
char str[INPUT_SIZE];

static int input_arr(float *arr, const int n, char name)
{
    float x;
    printf("Элементы массива %c (разделенные новой строкой):\n", name);
    for (int i = 0; i < n; i++) {
        fgets(str, INPUT_SIZE, stdin);
        x = strtof(str, &ptr);
        if (!x) {
            printf("Критическая ошибка: не найдено значение для ввода.\n");
            return 1;
        }
        else if (x >= FLT_MAX || x <= FLT_MIN) {
            printf("Критическая ошибка -> значение выходит за границы: %s\n", ptr);
            return 1;
        }
        arr[i] = x;
    }
    return 0;
}

int main() {
        printf("Введите количество точек (n): ");
        int n;
        fgets(str, INPUT_SIZE, stdin);
        long x = strtol(str, &ptr, 10);
        if (!x) {
            printf("Критическая ошибка: не найдено значение для ввода.\n");
            return 1;
        }
        else if(x >= INT_MAX || x < 4 ) { // минимально - 4 точки, поскольку 3 точки уже содержат в себе ответ на задачу
            printf("Критическая ошибка -> значение выходит за границы: %s\n", ptr);
            return 1;
        }

        n = (int)x;
        float X[n], Y[n];
        if (input_arr(X, n, 'X')) return 1;
        if (input_arr(Y, n, 'Y')) return 1;
        float **pX = arr_to_parr(X, n);
        float **pY = arr_to_parr(Y, n);
        int** inds = max_triang(pX, pY, n);
        free(pX); free(pY);
        if (inds != NULL)
            printf("Номера точек: %d %d %d\n", *inds[0], *inds[1], *inds[2]);
        else
            printf("Точки не найдены.");
        return 0;
}
