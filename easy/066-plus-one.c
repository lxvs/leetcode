#include <stdlib.h>
#include "066-plus-one.h"

int * plusOne (int * digits, int digitsSize, int * returnSize) {
    char carry = 1;

    *returnSize = digitsSize;
    if (++digits[digitsSize - 1] != 10) {
        return digits;
    }

    digits[digitsSize - 1] = 0;

    for (int i = digitsSize - 2; carry != 0 && i >= 0; i--) {
        if ((digits[i] += carry--) == 10) {
            digits[i] = 0;
            carry++;
        }
    }

    if (carry > 0) {
        int * digitsRealloc;

        if ((digitsRealloc = realloc (digits, sizeof *digitsRealloc * ++(*returnSize))) == NULL) {
            free (digits);
            *returnSize = 0;
            return NULL;
        }
        digits = digitsRealloc;

        for (int i = 1; i < *returnSize; i++) {
            digits[i] = digits[i - 1];
        }
        digits[0] = 1;
    }
    return digits;
}
