#include "088-merge-sorted-array.h"
#if DEBUG
#include <stdio.h>
#endif

#if DEBUG
static void printnums (int * nums, int size) {
    for (int i = 0; i < size; i++)
        fprintf(stderr, "%3d %5d\n", i, nums[i]);
    return;
}
#endif

static void insert (int * nums1, int pos, int value, int m) {
#if DEBUG
    fprintf(stderr, "Inserting %d before [%d] (%d)\n", value, pos, nums1[pos]);
#endif
    for (int i = m; i > pos; i--)
        nums1[i] = nums1[i-1];
    nums1[pos] = value;
#if DEBUG
    fprintf(stderr, "after insetion\n");
    printnums(nums1, m + 1);
#endif
}

void merge (int * nums1, int nums1Size, int m, int * nums2, int nums2Size, int n) {
    char inserted;

    for (int i = 0; i < n; i++) {
        inserted = 0;
#if DEBUG
        fprintf(stderr, "i = %d\n", i);
#endif
        for (int j = m - 1 + i; j >= 0; j--) {
#if DEBUG
            fprintf(stderr, "    i = %d, j = %d\n", i, j);
#endif
            if (nums2[i] < nums1[j] && (0 == j || nums2[i] >= nums1[j - 1])) {
#if DEBUG
                fprintf(stderr, "        i = %d, j = %d\n", i, j);
                fprintf(stderr,
                        "    insert(num1, %d, nums2[%d], %d); breaking\n",
                        j, i, m + i);
#endif
                insert(nums1, j, nums2[i], m + i);
                inserted = 1;
                break;
            }
#if DEBUG
            fprintf(stderr, "appended\n");
#endif
        }
        if (!inserted)
            insert(nums1, m + i, nums2[i], m + i);
    }
#if DEBUG
    fprintf(stderr, "final\n");
    printnums(nums1, m + n);
#endif

    return;
}
