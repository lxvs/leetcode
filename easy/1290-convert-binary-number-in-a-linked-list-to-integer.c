#include <lib/llist.h>

int getDecimalValue (struct ListNode * head) {
    int ret = 0;
    struct ListNode * p = head;

    while (p) {
        ret = (ret << 1) + p->val;
        p = p->next;
    }

    return ret;
}
