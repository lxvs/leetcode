#include "1759-count-number-of-homogenous-substrings.h"

#define SUM_MODULO      1000000007

static inline int getFullCount (int n) {
    int returnValue = 0;
    for (int i = 1; i <= n; i++) {
        returnValue = (returnValue + i) % SUM_MODULO;
    }
    return returnValue;
}

static inline void addToSum (int * sum, int addend) {
    *sum = (*sum + getFullCount (addend)) % SUM_MODULO;
}

int countHomogenous (char * s) {
    char current = s[0];
    int count = 0;
    int sum = 0;

    while (*s != '\0') {
        if (current == *s) {
            count++;
            s++;
            continue;
        }
        addToSum (&sum, count);
        current = *s;
        count = 0;
    }

    if (count > 0) {
        addToSum (&sum, count);
    }

    return sum;
}
