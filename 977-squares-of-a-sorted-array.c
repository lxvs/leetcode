#include <stdlib.h>

static void swap (int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

static int * BubbleSort (int * nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        char swapped = 0;
        for (int j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums + j, nums + j + 1);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
    return nums;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * sortedSquares (int * nums, int numsSize, int * returnSize) {
    int * ret = malloc(sizeof *ret * (*returnSize = numsSize));

    for (int i = 0; i < numsSize; i++)
        ret[i] = nums[i] * nums[i];

    return BubbleSort(ret, numsSize);
}
