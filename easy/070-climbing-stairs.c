#include <stdlib.h>
#include "070-climbing-stairs.h"

int climbStairs (int n) {
    int * result;
    int returnValue;

    if (n <= 2) {
        return n;
    }

    result = malloc (sizeof *result * n);
    result[0] = 1;
    result[1] = 2;
    for (int i = 2; i < n; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }

    returnValue = result[n - 1];
    free (result);
    return returnValue;
}
