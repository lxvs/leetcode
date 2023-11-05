#include <stdlib.h>
#include <stdio.h>
#include <lib/list.h>

Node * addListNode (Node * list, int value) {
    Node * p = list;

    if (p == NULL) {
        p = malloc (sizeof *p);
        p->val = value;
        p->next = NULL;
        return p;
    }

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = addListNode (p->next, value);

    return list;
}

void printLinkedList (const Node *list) {
    for (; list != NULL && list->next != NULL; list = list->next) {
        printf ("%d -> ", list->val);
    }
    if (list != NULL) {
        printf ("%d\n", list->val);
    }
}

void freeLinkedList (Node * list) {
    while (list != NULL) {
        Node * p = list;
        list = list->next;
        free (p);
    }
}

Node * parseArgsToLinkedList (char ** argv, int startingIndex) {
    Node * parsed = NULL;

    argv += startingIndex;
    while (*argv != NULL) {
        parsed = addListNode (parsed, atoi (*argv++));
    }
    return parsed;
}
