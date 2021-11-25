#include "lib/llist.h"
#include <stdlib.h>

struct ListNode * deleteDuplicates (struct ListNode* head) {
    struct ListNode * p = head;
    struct ListNode * q;
    struct ListNode * tmp;

    while (p) {
        q = p->next;
        while (q && q->val == p->val) {
            tmp = q;
            q = q->next;
            free(tmp);
        }
        p->next = q;
        p = p->next;
    }

    return head;
}
