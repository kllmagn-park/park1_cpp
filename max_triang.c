//
// Created by jellybe on 07.10.2021.
//

#include "max_triang.h"

static float form_S(float const *p1, float const *p2, float const *p3)
{
    return ((p2[1]-p3[1])*(p1[0]-p3[0]))-((p1[1]-p3[1])*(p2[0]-p3[0]));
}

float max_triang(float const *X, float const *Y, const int n)
{
    if (n < 3) return 0;
    float S = 0, S_tmp;
    float p1[2]; float p2[2]; float p3[2];
    for (int i = 0; i < n; i++)
    {
        p1[0] = X[i]; p1[1] = Y[i];
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            p2[0] = X[j]; p2[1] = Y[j];
            for (int k = 0; k < n; k++)
            {
                if (j == k || i == k) continue;
                p3[0] = X[k]; p3[1] = Y[k];
                S_tmp = form_S(p1, p2, p3);
                if (S_tmp > S) S = S_tmp;
            }
        }
    }
    return S;
}