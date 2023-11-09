#include "069-sqrtx.h"

int mySqrt (int x) {
    int low = 2;
    int high = x;

    if (x <= 1) {
        return x;
    }

    while (low <= high) {
        long mid = low + (high - low) / 2;
        if (mid * mid == x) {
            return mid;
        }
        if (mid * mid < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}
