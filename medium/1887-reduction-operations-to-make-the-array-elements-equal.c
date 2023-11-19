#include "1887-reduction-operations-to-make-the-array-elements-equal.h"

inline static void swap (int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static int * bubbleSort (int * array, int arraySize) {
    for (int i = 0, swapped = 0; i < arraySize; i++, swapped = 0) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swapped = 1;
                swap (array + j, array + j + 1);
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    return array;
}

int reductionOperations (int * nums, int numsSize) {
    int returnValue = 0;
    nums = bubbleSort (nums, numsSize);
    for (int i = 1, increment = 0; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            increment++;
        }
        returnValue += increment;
    }
    return returnValue;
}
