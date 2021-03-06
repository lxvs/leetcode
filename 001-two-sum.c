#include "001-two-sum.h"
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum (int* nums, int numsSize, int target, int* returnSize) {
    int * retval = malloc(sizeof *retval * (*returnSize = 2));

    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                retval[0] = i;
                retval[1] = j;
                return retval;
            }
        }
    }
    return NULL;
}
