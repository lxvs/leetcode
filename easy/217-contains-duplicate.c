#include "217-contains-duplicate.h"

bool containsDuplicate (const int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}
