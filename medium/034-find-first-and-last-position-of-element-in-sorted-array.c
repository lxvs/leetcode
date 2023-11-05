#include <stdlib.h>
#include "034-find-first-and-last-position-of-element-in-sorted-array.h"

int * searchRange (int * nums, int numsSize, int target, int * returnSize) {
    int * returnArray = malloc (sizeof *returnArray * (*returnSize = 2));
    int position = 0;

    returnArray[0] = returnArray[1] = -1;

    for (; position < numsSize && nums[position] <= target && returnArray[0] == -1; position++) {
        if (target == nums[position]) {
            returnArray[0] = position;
        }
    }

    if (returnArray[0] == -1) {
        return returnArray;
    }

    position--;

    while (position < numsSize && target == nums[position]) {
        position++;
    }

    returnArray[1] = position - 1;

    return returnArray;
}
