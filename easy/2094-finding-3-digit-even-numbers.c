#include <stdlib.h>
#include <stdbool.h>
#include "2094-finding-3-digit-even-numbers.h"

static void swap (int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void bubble (int * nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j ++) {
            if (nums[j] > nums[j + 1]) {
                swap (nums + j, nums + j + 1);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int * findEvenNumbers (int * digits, int digitsSize, int * returnSize) {
    unsigned char hashTable[1000] = {0};
    int * returnArray = malloc (sizeof *returnArray * 9 * 10 * 10);
    *returnSize = 0;

    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] % 2 != 0) {
            continue;
        }
        for (int j = 0; j < digitsSize; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0, num; k < digitsSize; k++) {
                if (j == k || i == k || digits[k] == 0) {
                    continue;
                }
                num = digits[i] + digits[j] * 10 + digits[k] * 100;
                if (hashTable[num] != 0) {
                    continue;
                }
                hashTable[num]++;
                returnArray[(*returnSize)++] = num;
            }
        }
    }
    bubble (returnArray, *returnSize);
    return returnArray;
}
