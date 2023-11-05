#include <stdlib.h>
#include "118-pascals-triangle.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int ** ret = malloc(sizeof *ret * numRows);

    if (!ret)
        return NULL;

    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof **returnColumnSizes * numRows);
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        ret[i] = malloc(sizeof **ret * (i + 1));
        for (int j = 0; j < i + 1; j++)
            ret[i][j] = i > 0 && j > 0 && j < i ? ret[i - 1][j - 1] + ret[i - 1][j] : 1;
    }

    return ret;
}
