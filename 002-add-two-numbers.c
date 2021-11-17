#include "002-add-two-numbers.h"
#include <stdlib.h>


struct ListNode* addTwoNumbers (struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* r;
    struct ListNode* l3;
    int sum;
    int carry = 0;

    l3 = (struct ListNode*) malloc(sizeof(struct ListNode));
    l3->val = 0;
    l3->next = NULL;
    r = l3;

    while (l1 || l2 || carry)
    {
        sum = 0;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        if (!r)
            r = (struct ListNode*) malloc(sizeof(struct ListNode));
        r->val = sum % 10;
        r->next = NULL;

        carry = sum / 10;

        if (l1 || l2 || carry) {
            r->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            r = r->next;
        }

    }

    return l3;
}
