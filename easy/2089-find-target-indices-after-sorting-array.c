#include <stdlib.h>
#if DEBUG
#include <lib/debug.h>
#include <lib/array.h>
#endif
#include "2089-find-target-indices-after-sorting-array.h"

static void swap (int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static int * bubble (int * nums, int numsSize) {
    for (int i = 0, swapped = 0; i < numsSize - 1; i++, swapped = 0) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swapped++;
                swap (nums + j, nums + j + 1);
            }
        }
        if (!swapped)
            break;
    }
    return nums;
}

int * targetIndices (int * nums, int numsSize, int target, int * returnSize) {
    int * returnArray = malloc (sizeof *returnArray * 100);
    *returnSize = 0;

    nums = bubble (nums, numsSize);

#if DEBUG
    printf ("after sorting: ");
    printIntegerArray (nums, numsSize);
#endif

    for (int i = 0; i < numsSize && nums[i] <= target; i++) {
        if (nums[i] == target) {
            returnArray[(*returnSize)++] = i;
        }
    }

    return returnArray;
}
