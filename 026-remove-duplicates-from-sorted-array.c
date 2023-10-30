#include "026-remove-duplicates-from-sorted-array.h"

int removeDuplicates (int * nums, int numsSize) {
    int newSize = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[newSize - 1]) {
            nums[newSize++] = nums[i];
        }
    }

    return newSize;
}
