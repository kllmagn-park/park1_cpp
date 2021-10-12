#include <stdio.h>
#include <stdlib.h>
#include "max_triang.h"

static int input_arr(float *arr, const int n, char name)
{
    printf("Элементы массива %c (разделенные пробелами): ", name);
    for (int i = 0; i < n; i++) if (scanf("%f", &arr[i]) != 1)
    {
        printf("Ошибка: неправильный формат ввода (%c).", name);
        return 1;
    };
    return 0;
}

int main() {
    int n;
    printf("Введите количество точек (n): ");
    if (scanf("%d", &n) != 1)
    {
        printf("Ошибка: неправильный формат ввода (n).");
        return 1;
    }
    float X[n], Y[n];
    if (input_arr(X, n, 'X')) return 1;
    if (input_arr(Y, n, 'Y')) return 1;
    float S = max_triang(X, Y, n);
    printf("Площадь треугольника: %f\n", S);
    return 0;
}
