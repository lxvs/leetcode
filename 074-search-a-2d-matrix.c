#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = 0;
    int j = 0;

    while (i < matrixSize - 1 && *matrix[i + 1] <= target)
        i++;

    while (j < matrixColSize[i] && matrix[i][j] < target)
        j++;

    return j < matrixColSize[i] ? matrix[i][j] == target : false;
}
