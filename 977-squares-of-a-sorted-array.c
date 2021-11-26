#include <stdlib.h>

static void InsertionSort (int * nums, int numsSize, int d) {
    int sorting;
    for (int i = d, j; i < numsSize; i += d) {
        sorting = nums[i];
        for (j = i - d; j >= 0 && nums[j] > sorting; j -= d)
            nums[j + d] = nums[j];
        nums[j + d] = sorting;
    }
    return;
}

static void ShellSort (int * nums, int numsSize) {
    for (int d = numsSize / 2; d > 0; d /= 2)
        for (int i = 0; i < d; i++)
            InsertionSort(nums, numsSize, d);
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * sortedSquares (int * nums, int numsSize, int * returnSize) {
    int * ret = malloc(sizeof *ret * (*returnSize = numsSize));

    for (int i = 0; i < numsSize; i++)
        ret[i] = nums[i] * nums[i];

    ShellSort(ret, numsSize);
    return ret;
}
