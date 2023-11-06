#include <stdlib.h>
#include "066-plus-one-enhanced.h"

//
// Plus One Enhanced: Add handling of input an integer as a digit.
//
int * plusOneEnhanced (int * digits, int digitsSize, int * returnSize) {
    int carry = 1;

    for (int i = digitsSize - 1; carry > 0 && i >= 0; i--, carry /= 10) {
        digits[i] += carry--;
        while (digits[i] >= 10) {
            digits[i] -= 10;
            carry += 10;
        }
    }

    *returnSize = digitsSize;

    while (carry > 0) {
        int * digitsRealloc;

        if ((digitsRealloc = realloc (digits, sizeof *digitsRealloc * ++(*returnSize))) == NULL) {
            free (digits);
            *returnSize = 0;
            return NULL;
        }
        digits = digitsRealloc;

        for (int i = *returnSize - 1; i > 0; i--) {
            digits[i] = digits[i - 1];
        }
        digits[0] = 0;
        while (carry > 0) {
            digits[0]++;
            carry--;
        }
        while (digits[0] >= 10) {
            digits[0] -= 10;
            carry += 10;
        }
        carry /= 10;
    }
    return digits;
}
