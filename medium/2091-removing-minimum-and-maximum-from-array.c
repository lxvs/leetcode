#include "2091-removing-minimum-and-maximum-from-array.h"

int minimumDeletions (int * nums, int numsSize) {
    int max = 0;
    int min = 0;
    int left, right;
    int leftest = 0;
    int rightest = numsSize - 1;
    int ret = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[max] < nums[i])
            max = i;
        if (nums[min] > nums[i])
            min = i;
    }

    left = max > min ? min : max;
    right = max < min ? min : max;
    if (left == right)
        return 1;

    if (left - leftest < rightest - right) {
        ret += left - leftest + 1;
        leftest += left - leftest + 1;
        left = right;

    } else {
        ret += rightest - right + 1;
        rightest -= rightest - right + 1;
        right = left;
    }

    if (left - leftest < rightest - right) {
        ret += left - leftest + 1;
        leftest += left - leftest + 1;
    } else {
        ret += rightest - right + 1;
        rightest -= rightest - right + 1;
    }

    return ret;
}
