#include <stdlib.h>
#include "566-reshape-the-matrix.h"

int ** matrixReshape (int ** mat, int matSize, int * matColSize, int r, int c, int * returnSize, int ** returnColumnSizes) {
    int ** reshaped;

    if (matSize * *matColSize != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    *returnSize = r;
    *returnColumnSizes = malloc (sizeof **returnColumnSizes * r);

    reshaped = malloc (sizeof *reshaped * r);
    for (int i = 0; i < r; i++) {
        reshaped[i] = malloc (sizeof **reshaped * c);
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            reshaped[i][j] = mat[(c * i + j) / *matColSize][(c * i + j) % *matColSize];

    return reshaped;
}
