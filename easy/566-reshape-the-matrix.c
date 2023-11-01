#include "566-reshape-the-matrix.h"
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int ** ret;

    if (matSize * *matColSize != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    *returnSize = r;
    *returnColumnSizes = malloc(sizeof **returnColumnSizes * r);

    ret = malloc(sizeof *ret * r);
    for (int i = 0; i < r; i++) {
        ret[i] = malloc(sizeof **ret * c);
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            ret[i][j] = mat[(c * i + j) / *matColSize][(c * i + j) % *matColSize];

    return ret;
}
