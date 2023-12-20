#include <stdlib.h>
#include "1913-maximum-product-difference-between-two-pairs.h"

static void merge_lists (int * nums, int left, int mid, int right) {
    int * temp = malloc (sizeof *temp * (right - left + 1));
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (int s = 0; s < right - left + 1; s++) {
        nums[left + s] = temp[s];
    }

    free (temp);
}

static void merge_sort (int * nums, int left, int right) {
    int mid;

    if (right <= left) {
        return;
    }

    mid = left + (right - left) / 2;

    merge_sort (nums, left, mid);
    merge_sort (nums, mid + 1, right);

    merge_lists (nums, left, mid, right);
}

int maxProductDifference (int * nums, int numsSize) {
    merge_sort (nums, 0, numsSize - 1);
    return nums[numsSize - 1] * nums[numsSize - 2] - nums[1] * nums[0];
}
