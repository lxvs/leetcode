#ifndef INCLUDED_LIST_H_
#define INCLUDED_LIST_H_

struct ListNode {
    int val;
    struct ListNode * next;
};

typedef struct ListNode Node;

Node * addListNode (Node * list, int value);

void printLinkedList (const Node * list);

void freeLinkedList (Node * list);

Node * parseArgsToLinkedList (char ** argv, int startingIndex);

#endif  /* INCLUDED_LIST_H_ */
