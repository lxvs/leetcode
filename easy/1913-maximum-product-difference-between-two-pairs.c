#include "1913-maximum-product-difference-between-two-pairs.h"

static void insertion_sort (int * nums, int numsSize) {
    for (int i = 1, j; i < numsSize; i++) {
        int num = nums[i];
        for (j = i - 1; j >= 0; j--) {
            if (num >= nums[j]) {
                break;
            }
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = num;
    }
}

int maxProductDifference (int * nums, int numsSize) {
    insertion_sort (nums, numsSize);
    return nums[numsSize - 1] * nums[numsSize - 2] - nums[1] * nums[0];
}
