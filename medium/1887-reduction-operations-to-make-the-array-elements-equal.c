#include "1887-reduction-operations-to-make-the-array-elements-equal.h"

#define MAX_VALUE   50000
#define MIN_VALUE   1

int reductionOperations (int * nums, int numsSize) {
    int frequency[MAX_VALUE - MIN_VALUE + 1] = {0};
    int max = MIN_VALUE;
    int min = MAX_VALUE;
    int weight = 0;
    int returnValue = 0;

    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        frequency[value]++;
        if (value > max) {
            max = value;
        }
        if (value < min) {
            min = value;
        }
    }

    for (int i = min; i <= max; i++) {
        if (frequency[i] == 0) {
            continue;
        }
        returnValue += weight++ * frequency[i];
    }

    return returnValue;
}
