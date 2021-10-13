//
// Created by jellybe on 07.10.2021.
//

#include "./max_triang.h"

const float** arr_to_parr(float *arr, const int n) {
    const float **out = (const float**)malloc(sizeof(float*)*n);
    for (int i = 0; i < n; i++) out[i] = &arr[i];
    return out;
}

// =========================================================

struct point {
    float x;
    float y;
};
typedef struct point point;

static float form_S(const point p1, const point p2, const point p3) {
    return ((p2.y-p3.y)*(p1.x-p3.x))-((p1.y-p3.y)*(p2.x-p3.x));
}

int** max_triang(const float **X, const float **Y, int n) {
    if (n < 3) {  // доступно меньше трех точек
        return NULL;
    }
    static int pi1, pi2, pi3;  // возвращаемые индексы точек
    pi1 = 0, pi2 = 1, pi3 = 2;
    int **pis = (int**)malloc(sizeof(int*)*3);
    pis[0] = &pi1; pis[1] = &pi2; pis[2] = &pi3;
    if (n == 3) {
        return pis;
    }
    float S = 0, S_tmp;
    point p1, p2, p3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j)
            for (int k = j + 1; k < n; ++k) {
                p1 = (point) {*X[i], *Y[i]};
                p2 = (point) {*X[j], *Y[j]};
                p3 = (point) {*X[k], *Y[k]};
                S_tmp = form_S(p1, p2, p3);
                if (S_tmp > S) {
                    S = S_tmp;
                    pi1 = i;
                    pi2 = j;
                    pi3 = k;
                }
            }
    }
    return (S > 0) ? pis: NULL;
}
