#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = 0;
    int l = 0;
    int r, m;

    if (target < matrix[0][0] ||
            target > matrix[matrixSize - 1][matrixColSize[matrixSize - 1] - 1])
        return false;

    while (i < matrixSize - 1 && *matrix[i + 1] <= target)
        i++;

    r = matrixColSize[i] - 1;

    while (l <= r) {
        m = (l + r) / 2;
        if (target < matrix[i][m]) {
            r = m - 1;
            continue;
        }
        if (target > matrix[i][m]) {
            l = m + 1;
            continue;
        }
        return true;
    }

    return false;
}
