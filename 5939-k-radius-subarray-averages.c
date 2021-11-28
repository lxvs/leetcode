#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * getAverages (int * nums, int numsSize, int k, int * returnSize) {
    int * ret = malloc(sizeof *ret * (*returnSize = numsSize));
    long sum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i < k || i >= numsSize - k) {
            ret[i] = -1;
            continue;
        }
        if (i == k) {
            for (int j = 0; j < 2 * k + 1; j++)
                sum += nums[j];
            ret[i] = sum / (2 * k + 1);
            continue;
        }
        sum -= nums[i - k - 1];
        sum += nums[i + k];
        ret[i] = sum / (2 * k + 1);
    }

    return ret;
}
