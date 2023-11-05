#include <stdlib.h>
#include "977-squares-of-a-sorted-array.h"

static void InsertionSort (int * nums, int numsSize, int d) {
    for (int i = d, sorting, j; i < numsSize; i += d) {
        sorting = nums[i];
        for (j = i - d; j >= 0 && nums[j] > sorting; j -= d) {
            nums[j + d] = nums[j];
        }
        nums[j + d] = sorting;
    }
}

static void ShellSort (int * nums, int numsSize) {
    for (int d = numsSize / 2; d > 0; d /= 2) {
        for (int i = 0; i < d; i++) {
            InsertionSort (nums, numsSize, d);
        }
    }
}

int * sortedSquares (int * nums, int numsSize, int * returnSize) {
    int * sorted = malloc (sizeof *sorted * (*returnSize = numsSize));

    for (int i = 0; i < numsSize; i++) {
        sorted[i] = nums[i] * nums[i];
    }

    ShellSort (sorted, numsSize);
    return sorted;
}
