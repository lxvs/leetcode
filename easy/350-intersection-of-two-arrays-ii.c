#include <stdlib.h>
#include "350-intersection-of-two-arrays-ii.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect (int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int hashTable[1001] = {0};
    int * returnArray = malloc (sizeof *returnArray * min (nums1Size, nums2Size));
    *returnSize = 0;

    for (int i = 0; i < nums1Size; i++) {
        hashTable[nums1[i]]++;
    }

    for (int i = 0; i < nums2Size; i++) {
        if (hashTable[nums2[i]] != 0) {
            returnArray[(*returnSize)++] = nums2[i];
            hashTable[nums2[i]]--;
        }
    }

    return returnArray;
}
