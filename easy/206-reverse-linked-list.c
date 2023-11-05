#include <stddef.h>
#include <lib/list.h>

struct ListNode * reverseList (struct ListNode * head) {
    struct ListNode * p = head;
    struct ListNode * q;
    struct ListNode * r;

    if (p != NULL) {
        if (p->next != NULL) {
            q = p->next;
            p->next = NULL;
            if (q->next != NULL) {
                r = q->next;
                q->next = NULL;
            } else {
                p->next = NULL;
                q->next = p;
                return q;
            }
        } else {
            return p;
        }
    } else {
        return NULL;
    }

    while (r != NULL) {
        q->next = p;
        p = q;
        if (r->next == NULL) {
            r->next = q;
            break;
        }
        q = r;
        r = r->next;
        q->next = p;
    }

    return r;
}
