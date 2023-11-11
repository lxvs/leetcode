#include "070-climbing-stairs.h"

int climbStairs (int n) {
    int prev1, prev2;
    int returnValue;

    if (n <= 2) {
        return n;
    }

    prev2 = 1;
    prev1 = 2;

    for (int i = 2; i < n; i++) {
        returnValue = prev1 + prev2;
        prev2 = prev1;
        prev1 = returnValue;
    }

    return returnValue;
}
