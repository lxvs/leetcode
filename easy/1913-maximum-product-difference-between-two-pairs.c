#include "1913-maximum-product-difference-between-two-pairs.h"

#define MIN_VALUE 1
#define MAX_VALUE 10000

int maxProductDifference (int * nums, int numsSize) {
    int max[2] = {MIN_VALUE, MIN_VALUE};
    int min[2] = {MAX_VALUE, MAX_VALUE};

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
