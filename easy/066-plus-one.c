#include <stdlib.h>
#include "066-plus-one.h"

int * plusOne (int * digits, int digitsSize, int * returnSize) {
    char carry = 1;

    for (int i = digitsSize - 1; carry != 0 && i >= 0; i--) {
        digits[i] += carry--;
        if (digits[i] >= 10) {
            digits[i] -= 10;
            carry++;
        }
    }

    *returnSize = digitsSize;

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
        digits[0] += carry--;
    }
    return digits;
}
