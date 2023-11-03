#include "088-merge-sorted-array.h"

static void insert (int * nums1, int pos, int value, int m) {
    for (int i = m; i > pos; i--)
        nums1[i] = nums1[i-1];
    nums1[pos] = value;
}

void merge (int * nums1, int nums1Size, int m, int * nums2, int nums2Size, int n) {
    char inserted;

    for (int i = 0; i < n; i++) {
        inserted = 0;
        for (int j = m - 1 + i; j >= 0; j--) {
            if (nums2[i] < nums1[j] && (0 == j || nums2[i] >= nums1[j - 1])) {
                insert(nums1, j, nums2[i], m + i);
                inserted = 1;
                break;
            }
        }
        if (!inserted)
            insert(nums1, m + i, nums2[i], m + i);
    }

    return;
}
