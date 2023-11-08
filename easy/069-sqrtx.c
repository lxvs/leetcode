#include "069-sqrtx.h"

int mySqrt (int x) {
    int low = 2;
    int high = x;
    long mid = low + (high - low) / 2;

    if (x <= 1) {
        return x;
    }

    while (low < high - 1) {
        if (mid * mid == x) {
            return mid;
        }
        if (mid * mid < x) {
            low = mid;
        } else {
            high = mid;
        }
        mid = low + (high - low) / 2;
    }

    return mid;
}
