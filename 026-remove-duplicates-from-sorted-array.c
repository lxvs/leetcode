#include "026-remove-duplicates-from-sorted-array.h"

int removeDuplicates (int * nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        while (nums[i] == nums[i - 1] && i < numsSize) {
            numsSize--;
            for (int j = i; j < numsSize; j++) {
                nums[j] = nums[j + 1];
            }
        }
    }

    return numsSize;
}
