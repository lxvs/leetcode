#include <lib/llist.h>

#include <stdlib.h>

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode * p;

    if (!head)
        return NULL;

    while (head && head->val == val) {
        p = head;
        head = head->next;
        free(p);
    }

    for (struct ListNode * q = head; q && q->next; q = q->next)
        while (q->next && q->next->val == val) {
            p = q->next;
            q->next = q->next->next;
            free(p);
        }

    return head;
}
