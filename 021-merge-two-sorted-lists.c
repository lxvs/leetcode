#include "lib/llist.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * ret;

    if (!l1)
        return l2;

    if (!l2)
        return l1;

    ret = l1->val > l2->val ? l2 : l1;
    ret->next = l1->val > l2->val ? mergeTwoLists(l1, l2->next) : mergeTwoLists(l1->next, l2);

    return ret;
}
