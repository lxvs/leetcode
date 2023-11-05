#include <stddef.h>
#include "021-merge-two-sorted-lists.h"

struct ListNode * mergeTwoLists (struct ListNode * l1, struct ListNode * l2) {
    struct ListNode * merged;

    if (l1 == NULL) {
        return l2;
    }

    if (l2 == NULL) {
        return l1;
    }

    merged = (l1->val > l2->val) ? l2 : l1;
    merged->next = (l1->val > l2->val) ? mergeTwoLists(l1, l2->next) : mergeTwoLists(l1->next, l2);

    return merged;
}
