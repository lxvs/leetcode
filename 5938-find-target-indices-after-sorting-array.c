#include <stdlib.h>

static void swap (int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

static int * bubble (int * nums, int numsSize) {
    for (int i = 0, swapped = 0; i < numsSize - 1; i++, swapped = 0) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swapped++;
                swap(nums + j, nums + j + 1);
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
int * targetIndices (int * nums, int numsSize, int target, int * returnSize) {
    int * ret = malloc(sizeof *ret * 100);
    *returnSize = 0;

    nums = bubble(nums, numsSize);
    for (int i = 0; i < numsSize && nums[i] <= target; i++)
        if (nums[i] == target)
            ret[(*returnSize)++] = i;

    return ret;
}
