#include <stdlib.h>
#include "350-intersection-of-two-arrays-ii.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int tab[1001] = {0};
    int * ret = malloc(sizeof *ret * min(nums1Size, nums2Size));
    *returnSize = 0;

    for (int i = 0; i < nums1Size; i++)
        tab[nums1[i]]++;


    for (int i = 0; i < nums2Size; i++)
        if (tab[nums2[i]]) {
            ret[(*returnSize)++] = nums2[i];
            tab[nums2[i]]--;
        }

    return ret;
}
