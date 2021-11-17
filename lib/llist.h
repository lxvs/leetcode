#ifndef __LLIST_H__
#define __LLIST_H__

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode Node;

Node * AddValue (Node * list, int value);
void DelValue (Node * list, int value);
void PrintList (const Node * list);
void GenRandList (Node * list, int length);

#endif
