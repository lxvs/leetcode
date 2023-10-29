#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Node * AddValue (Node * list, int value) {
    Node * p;

    if (!list) {
        list = malloc(sizeof *list);
        list->val = value;
        list->next = NULL;
    } else {
        p = list;
        while (p->next)
            p=p->next;
        p->next = (Node *) malloc(sizeof(Node));
        p = p->next;
        p->val = value;
        p->next = NULL;
    }
    return list;
}

void DelValue (Node *list, int value) {
    Node *p;
    if (!list) return;
    if (list->val == value) {
        p=list;
        list=list->next;
        free(p);
        DelValue(list,value);
    } else {
        DelValue(list->next, value);
    }
    return;
}

void PrintList (const Node *list) {
    const Node *p = list;

    if (!p) {
        fprintf(stdout, "PrintList: empty list\n");
        return;
    }

    fprintf(stdout, "=======================\n");
    fprintf(stdout, " %5s %15s\n", "Index", "Value");
    fprintf(stdout, "-----------------------\n");
    for (int i = 0; p; i++) {
        fprintf(stdout, " %5d %15d\n", i, p->val);
        if (p->val < -65536 || p->val > 65535) {
            fprintf(stderr, "warning: It seems that something is wrong, breaking.\n");
            break;
        }
        p = p->next;
    }
    fprintf(stdout, "=======================\n");
    return;
}

void GenRandList (Node *list, int length) {
    Node *p;

    if(!list) list = (Node*) malloc(sizeof(Node*));
    p=list;
    srand((unsigned) time(NULL));
    p->val = rand() % 64;
    p->next = NULL;
    for(int i = 1; i < length; i++) {
        p->next = (Node*) malloc(sizeof(Node*));
        p = p->next;
        p->val = rand() % 64;
        p->next = NULL;
    }
}

void InsertionSort (Node *list) {
    Node *p = list->next;
    Node *q;
    while(p) {
        q = list;
        while(q->next && q->next != p) {
            if(p->val) {
                p->next = q->next;
                q->next = p;
            }
        }
    }
    return;
}
