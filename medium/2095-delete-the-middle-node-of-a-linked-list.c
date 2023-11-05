#include <stdlib.h>
#include "2095-delete-the-middle-node-of-a-linked-list.h"

struct ListNode * deleteMiddle (struct ListNode * head) {
    struct ListNode * p;
    struct ListNode * q;
    struct ListNode * prev;

    if (head->next == NULL) {
        free (head);
        return NULL;
    }

    for (prev = p = q = head; p != NULL && q != NULL && q->next != NULL; prev = p, p = p->next, q = q->next->next);

    prev->next = p->next;
    free (p);

    return head;
}
