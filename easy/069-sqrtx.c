#include "069-sqrtx.h"

int mySqrt (int x) {
    int i = 0;
    for (; i * i < x; i++);
    return (i * i == x) ? i : i - 1;
}
