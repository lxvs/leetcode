#include "217-contains-duplicate.h"
#include <stdbool.h>
#if DEBUG
#include <stdio.h>
#endif

bool containsDuplicate (const int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
#if DEBUG
        fprintf(stderr, "nums[%d] = %d\n", i, nums[i]);
#endif
        for (int j = 0; j < i; j++) {
#if DEBUG
            fprintf(stderr, "  nums[%d] = %d\n", j, nums[j]);
#endif
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}
