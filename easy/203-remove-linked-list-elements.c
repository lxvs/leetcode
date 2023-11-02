#include <stdlib.h>
#include "203-remove-linked-list-elements.h"

struct ListNode * removeElements (struct ListNode * head, int val) {
    struct ListNode * walker;

    while (head != NULL && head->val == val) {
        struct ListNode * p = head;
        head = head->next;
        free (p);
    }

    
    for (walker = head; walker != NULL; walker = walker->next) {
        while (walker->next != NULL && walker->next->val == val) {
            struct ListNode * p = walker->next;
            walker->next = walker->next->next;
            free (p);
        }
    }

    return head;
}
