#include "053-maximum-subarray.h"

int maxSubArray (int * nums, int numsSize) {
    int sum = 0;
    int max = *nums;

    for (int i = 0; i < numsSize; i++) {
        sum = nums[i] > sum + nums[i] ? nums[i] : sum + nums[i];
        if (max < sum)
            max = sum;
    }

    return max;
}
