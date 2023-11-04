#include <stdlib.h>
#include "083-remove-duplicates-from-sorted-list.h"

struct ListNode * deleteDuplicates (struct ListNode* head) {
    struct ListNode * p = head;

    for (struct ListNode * node; p != NULL; p = p->next) {
        while (p != NULL && (node = p->next) != NULL && node->val == p->val) {
            p->next = node->next;
            free (node);
            node = p->next;
        }
    }

    return head;
}
