#include <string.h>
#include "1759-count-number-of-homogenous-substrings.h"

#define SUM_MODULO      1000000007

int countHomogenous (char * s) {
    int i = 0;
    int j = 0;
    int length = strlen (s);
    int sum = 0;

    while (j < length) {
        while (j < length && s[i] == s[j]) {
            sum = (sum + (j - i + 1)) % SUM_MODULO;
            j++;
        }
        i = j;
    }

    return sum;
}
