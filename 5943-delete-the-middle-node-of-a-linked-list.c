#include "lib/llist.h"
#include <stdlib.h>

struct ListNode * deleteMiddle (struct ListNode * head) {
    if (!head->next) {
        free(head);
        return NULL;
    }

    struct ListNode * p, * q, * prev;
    for (prev = p = q = head; p && q && q->next; prev = p, p = p->next, q = q->next->next);

    prev->next = p->next;
    free(p);

    return head;
}
