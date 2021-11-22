#include "350-intersection-of-two-arrays-ii.h"

#include <stdlib.h>

#if DEBUG
#include <stdio.h>
#endif

static int DeleteValue (int * nums, int size, int idx);
#if DEBUG
static void PrintIa (const int * nums, int size);
#endif

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int * n1 = malloc(sizeof *n1 * nums1Size);
    int * n2 = malloc(sizeof *n2 * nums2Size);
    int * ret = malloc(sizeof *ret * (nums1Size <= nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;

    for (int i = 0; i < nums1Size; i++)
        n1[i] = nums1[i];

    for (int i = 0; i < nums2Size; i++)
        n2[i] = nums2[i];

    for (int i = 0; i < nums1Size; i++)
        for (int j = 0; j < nums2Size; j++)
            while (i < nums1Size && j < nums2Size && n1[i] == n2[j]) {
#if DEBUG
                fprintf(stderr, "n1[%d]:\n", nums1Size);
                PrintIa(n1, nums1Size);
                fprintf(stderr, "n2[%d]:\n", nums2Size);
                PrintIa(n2, nums2Size);
                fprintf(stderr, "ret[%d] <- %d\n", *returnSize, n1[i]);
                fprintf(stderr, "    i   = %2d, j   = %2d\n", i, j);
                putchar('\n');
#endif
                ret[(*returnSize)++] = n1[i];
                DeleteValue(n1, nums1Size--, i);
                DeleteValue(n2, nums2Size--, j);
                j = 0;
            }
#if DEBUG
    fprintf(stderr, "\nFinal n1[%d]:\n", nums1Size);
    PrintIa(n1, nums1Size);
    fprintf(stderr, "\nFinal n2[%d]:\n", nums2Size);
    PrintIa(n2, nums2Size);
    putchar('\n');
#endif
    free(n1);
    free(n2);
    return ret;
}

static int DeleteValue (int * nums, int size, int idx) {
    if (idx >= size)
        return -1;

    for (int i = idx; i < size - 1; i++)
        nums[i] = nums[i + 1];

    return 0;
}

#if DEBUG
static void PrintIa (const int * nums, int size) {
    for (int i = 0; i < size; i++)
        fprintf(stderr, "[%d] = %d\n", i, nums[i]);
}
#endif
