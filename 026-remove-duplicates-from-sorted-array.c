#include "026-remove-duplicates-from-sorted-array.h"
#include <stdio.h>

void printArray (int *array, int arraySize) {
    for (int i=0; i<arraySize; i++)
        printf("array[%d]=%d\n", i, array[i]);
    return;
}

int removeDuplicates (int* nums, int numsSize) {

    for (int i=1; i<numsSize; i++)
    {
        // printf("i=%d\n", i);
        if (nums[i] == nums[i-1])
        {
            for (int j=i; j<numsSize-1; j++)
            {
                // printf("j=%d\n", j);
                nums[j] = nums[j+1];
            }
        }
    }

    return 0;

}
