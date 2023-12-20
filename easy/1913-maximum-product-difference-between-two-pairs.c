#include "1913-maximum-product-difference-between-two-pairs.h"

static inline void swap (int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void bubble_sort (int * nums, int numsSize) {
    while (1) {
        char swapped = 0;
        int sortedSize = 0;
        for (int i = 1; i < numsSize - sortedSize; i++) {
            if (nums[i - 1] > nums[i]) {
                swap (&nums[i - 1], &nums[i]);
                swapped = 1;
            }
        }
        sortedSize++;
        if (!swapped) {
            break;
        }
    }
}

int maxProductDifference (int * nums, int numsSize) {
    bubble_sort (nums, numsSize);
    return nums[numsSize - 1] * nums[numsSize - 2] - nums[1] * nums[0];
}
