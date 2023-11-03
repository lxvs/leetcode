#include <lib/list.h>
#include <stdlib.h>

struct ListNode * reverseList (struct ListNode * head) {
    struct ListNode * p = head;
    struct ListNode * q;
    struct ListNode * r;

    if (p) {
        if (p->next) {
            q = p->next;
            p->next = NULL;
            if (q->next) {
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

    while (r) {
        q->next = p;
        p = q;
        if (!r->next) {
            r->next = q;
            break;
        }
        q = r;
        r = r->next;
        q->next = p;
    }

    return r;
}
