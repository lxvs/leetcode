#ifndef INCLUDED_LIST_H_
#define INCLUDED_LIST_H_

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode Node;

Node * AddValue (Node * list, int value);
void DelValue (Node * list, int value);
void PrintList (const Node * list);
void GenRandList (Node * list, int length);
void FreeLinkedList (Node * list);
Node * parseArgsToLinkedList (char ** argv);

#endif
