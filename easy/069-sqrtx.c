#include "069-sqrtx.h"

int mySqrt (int x) {
    int i;
    for (i = 1; x != 0 && x / i >= i; i++);
    return ((x != 0) && (x / i == i) && (x % i == 0)) ? i : i - 1;
}
