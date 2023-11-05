#include <stdlib.h>
#include <lib/array.h>
#include "002-add-two-numbers.h"

struct ListNode * addTwoNumbers (struct ListNode * l1, struct ListNode * l2) {
    struct ListNode * l3 = malloc (sizeof *l3);
    struct ListNode * p = l3;
    int sum;
    int carry = 0;

    l3->val = 0;
    l3->next = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        sum = 0;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        if (p == NULL) {
            p = malloc (sizeof *p);
        }
        p->val = sum % 10;
        p->next = NULL;

        carry = sum / 10;

        if (l1 != NULL || l2 != NULL || carry != 0) {
            p->next = malloc (sizeof *p->next);
            p = p->next;
        }
    }

    return l3;
}
