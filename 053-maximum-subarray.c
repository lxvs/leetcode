#include "053-maximum-subarray.h"
#if DEBUG
#include <stdio.h>
#endif

int maxSubArray (int * nums, int numsSize) {
    int sum = 0;
    int max = 0;
    int org = 0;
    int len;

    while (org < numsSize) {
        len = 0;
        if (nums[org] <= 0) {
#if DEBUG
            fprintf(stderr, "nums[%d] = %d, continuing loop.\n",
                    org, nums[org]);
#endif
            org++;
            continue;
        }
#if DEBUG
        fprintf(stderr, "org = %-3d, len = %-3d, nums[x] = %-3d\n",
                org, len, nums[org + len]);
#endif
        sum = 0;
        while (org + len < numsSize) {
            sum += nums[org + len++];
#if DEBUG
        fprintf(stderr, "    org = %-3d, len = %-3d, sum = %-5d\n",
                org, len - 1, sum);
#endif
            if (max < sum)
                max = sum;
            if (sum < 0)
                break;
        }
        org++;
    }

    return max;
}
