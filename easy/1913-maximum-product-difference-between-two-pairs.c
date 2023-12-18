#include "1913-maximum-product-difference-between-two-pairs.h"

int maxProductDifference (int * nums, int numsSize) {
    int max[2] = {nums[0], nums[1]};
    int min[2] = {nums[2], nums[3]};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (max[i] < nums[j] && max[i ^ 1] != nums[j]) {
                max[i] = nums[j];
            }
            if (min[i] > nums[j] && min[i ^ 1] != nums[j]) {
                min[i] = nums[j];
            }
        }
    }

    return max[0] * max[1] - min[0] * min[1];
}
