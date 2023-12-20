#include "1913-maximum-product-difference-between-two-pairs.h"

static inline void swap (int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void quick_sort (int * nums, int left, int right) {
    int pivotIndex = left;
    int pivot;
    char luck = 0;

    if (left >= right) {
        return;
    }

    pivot = nums[pivotIndex];

    for (int i = pivotIndex + 1; i < right + 1; i++) {
        if (nums[i] < pivot || (nums[i] == pivot && (luck = !luck))) {
            swap (&nums[i], &nums[++pivotIndex]);
        }
    }
    swap (&nums[left], &nums[pivotIndex]);

    quick_sort (nums, left, pivotIndex - 1);
    quick_sort (nums, pivotIndex + 1, right);
}

int maxProductDifference (int * nums, int numsSize) {
    quick_sort (nums, 0, numsSize - 1);
    return nums[numsSize - 1] * nums[numsSize - 2] - nums[1] * nums[0];
}
