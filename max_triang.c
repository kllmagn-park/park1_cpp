//
// Created by jellybe on 07.10.2021.
//

#include "max_triang.h"

float** arr_to_parr(float *arr, const int n)
{
    float **out = (float**)malloc(sizeof(float*)*n);
    for (int i = 0; i < n; i++) out[i] = &arr[i];
    return out;
}

// =========================================================


struct combo
{
    int* arr; int size;
};
typedef struct combo combo;

struct combos
{
    combo *arr; int size;
};
typedef struct combos combos;

static float form_S(float **p1, float **p2, float **p3)
{
    return ((*p2[1]-*p3[1])*(*p1[0]-*p3[0]))-((*p1[1]-*p3[1])*(*p2[0]-*p3[0]));
}

static combos form_combo(int* arr, const int n, const int k) {
    if (k == 1) {
        combo *a = (combo *) malloc(sizeof(combo) * n);
        for (int i = 0; i < n; i++) {
            int *result = (int *) malloc(sizeof(int));
            memcpy(result, arr + i, sizeof(int));
            a[i] = (combo) {result, 1};
        }
        return (combos){a, n};
    }
    else if (n == k)
    {
        combo *a = (combo*)malloc(sizeof(combo));
        int *result = (int *) malloc(sizeof(int)*n);
        memcpy(result, arr, sizeof(int)*n);
        a[0] = (combo){result, k};
        return (combos){a, 1};
    }
    else
    {
        combos cbs = form_combo(arr+1, n-1, k-1);
        combos cbs_add = form_combo(arr+1, n-1, k);
        combo *res = malloc(sizeof(combo)*(cbs.size+cbs_add.size));
        for (int i = 0; i < cbs.size; i++)
        {
            int *result = (int*)malloc(sizeof(int)*k);
            memcpy(result, arr, sizeof(int));
            memcpy(result+1, cbs.arr[i].arr, sizeof(int)*cbs.arr[i].size);
            res[i] = (combo){result, k};
            free(cbs.arr[i].arr);
        }
        for (int i = cbs.size; i < cbs_add.size+cbs.size; i++)
        {
            int *result = (int*)malloc(sizeof(int)*k);
            memcpy(result, cbs_add.arr[i-cbs.size].arr, sizeof(int)*k);
            res[i] = (combo){result, k};
            free(cbs_add.arr[i-cbs.size].arr);
        }
        free(cbs.arr); free(cbs_add.arr);
        return (combos){res, cbs.size+cbs_add.size};
    }
}

static int pi1, pi2, pi3;

int** max_triang(float **X, float **Y, const int n)
{
    if (n < 3) return NULL;
    float S = 0, S_tmp;
    float *p1[2]; float *p2[2]; float *p3[2];
    pi1 = 0, pi2 = 1, pi3 = 2;
    int **pis = (int**)malloc(sizeof(int*)*3);
    pis[0] = &pi1; pis[1] = &pi2; pis[2] = &pi3;
    if (n == 3) return pis;
    int inds[n];
    for (int i = 0; i < n; i++) inds[i] = i;
    combo cb; combos cbs = form_combo(inds, n, 3);
    for (int s = 0; s < cbs.size; s++) {
        int i, j, k;
        cb = cbs.arr[s];
        i = cb.arr[0]; j = cb.arr[1]; k = cb.arr[2];
        p1[0] = X[i]; p1[1] = Y[i];
        p2[0] = X[j]; p2[1] = Y[j];
        p3[0] = X[k]; p3[1] = Y[k];
        S_tmp = form_S(p1, p2, p3);
        if (S_tmp > S) {
            S = S_tmp;
            pi1 = i; pi2 = j; pi3 = k;
        }
        free(cb.arr);
    }
    free(cbs.arr);
    return (S > 0) ? pis: NULL;
}