#include "./tools.h"

const float** arr_to_parr(float *arr, int n) {
    const float **out = (const float**)malloc(sizeof(float*)*n);
    if (out == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) out[i] = &arr[i];
    return out;
}

void freep(void** arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}
