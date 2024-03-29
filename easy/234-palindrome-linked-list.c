#include <stdlib.h>
#include "234-palindrome-linked-list.h"

bool isPalindrome_ll (struct ListNode * head) {
    struct ListNode * p = head;
    struct ListNode * q;
    struct ListNode * tail;
    bool ret = true;
    int len = 1;

    q = malloc(sizeof *q);
    q->val = p->val;
    q->next = NULL;
    tail = q;

    for (; (p = p->next); len++) {
        q = malloc(sizeof *q);
        q->val = p->val;
        q->next = tail;
        tail = q;
    }

    p = head;
    q = tail;
    for (int i = 0; i < len/2 && p && q; i++) {
        if (p->val != q->val)
            ret = false;
        p = p->next;
        q = q->next;
    }

    while (tail != NULL) {
        Node * toBeFreed = tail;
        tail = tail->next;
        free (toBeFreed);
    }

    return ret;
}
