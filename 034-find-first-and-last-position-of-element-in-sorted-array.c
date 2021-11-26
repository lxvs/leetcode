#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * searchRange(int * nums, int numsSize, int target, int * returnSize) {
    int * ret = malloc(sizeof *ret * (*returnSize = 2));
    int i = 0;

    ret[0] = ret[1] = -1;

    for (; i < numsSize && nums[i] <= target && ret[0] == -1; i++)
        if (target == nums[i])
            ret[0] = i;

    if (ret[0] == -1)
        return ret;

    i--;

    while (i < numsSize && target == nums[i])
        i++;

    ret[1] = i - 1;

    return ret;
}
