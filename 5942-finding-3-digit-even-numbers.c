#include <stdlib.h>
#include <stdbool.h>

static void swap (int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

static void bubble (int * nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j ++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums + j, nums + j + 1);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    unsigned char t[1000] = {0};
    int * ret = malloc(sizeof *ret * 9 * 10 * 10);
    *returnSize = 0;

    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] % 2)
            continue;
        for (int j = 0; j < digitsSize; j++) {
            if (i == j)
                continue;
            for (int k = 0; k < digitsSize; k++) {
                if (j == k || i == k || digits[k] == 0)
                    continue;
                int num = digits[i] + digits[j] * 10 + digits[k] * 100;
                if (t[num])
                    continue;
                t[num]++;
                ret[(*returnSize)++] = num;
            }
        }
    }
    bubble(ret, *returnSize);
    return ret;
}
