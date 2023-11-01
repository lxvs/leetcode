#include "053-maximum-subarray.h"
#if DEBUG
#include <stdio.h>
#endif

int maxSubArray (int * nums, int numsSize) {
    int sum = 0;
    int max = *nums;

    for (int i = 0; i < numsSize; i++) {
#if DEBUG
        fprintf(stderr,
                "sum     %10d\n"
                "nums[i] %10d\n",
                sum, nums[i]);
#endif
        sum = nums[i] > sum + nums[i] ? nums[i] : sum + nums[i];
        if (max < sum)
            max = sum;
    }

    return max;
}
