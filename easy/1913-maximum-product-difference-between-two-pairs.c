#include "1913-maximum-product-difference-between-two-pairs.h"

static inline void swap (int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void selection_sort (int * nums, int numsSize) {
    int min_index = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        swap (&nums[i], &nums[min_index]);
        min_index = i + 1;
    }
}

int maxProductDifference (int * nums, int numsSize) {
    selection_sort (nums, numsSize);
    return nums[numsSize - 1] * nums[numsSize - 2] - nums[1] * nums[0];
}
