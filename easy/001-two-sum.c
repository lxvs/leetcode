#include <stdlib.h>
#include "001-two-sum.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum (int* nums, int numsSize, int target, int* returnSize) {
    int * returnArray = malloc (sizeof *returnArray * (*returnSize = 2));

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnArray[0] = i;
                returnArray[1] = j;
                return returnArray;
            }
        }
    }
    free (returnArray);
    return NULL;
}
