#include <stddef.h>
#include "1290-convert-binary-number-in-a-linked-list-to-integer.h"

int getDecimalValue (struct ListNode * head) {
    int decimal = 0;

    for (; head != NULL; head = head->next) {
        decimal = (decimal << 1) + head->val;
    }

    return decimal;
}
