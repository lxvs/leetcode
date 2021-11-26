#include <stdlib.h>

static void InsertionSort (int * nums, int numsSize) {
    int sorting;
    for (int i = 1, j; i < numsSize; i++) {
        sorting = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > sorting; j--)
            nums[j + 1] = nums[j];
        nums[j + 1] = sorting;
    }
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * sortedSquares (int * nums, int numsSize, int * returnSize) {
    int * ret = malloc(sizeof *ret * (*returnSize = numsSize));

    for (int i = 0; i < numsSize; i++)
        ret[i] = nums[i] * nums[i];

    InsertionSort(ret, numsSize);
    return ret;
}
