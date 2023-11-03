#include <stdlib.h>
#include <stdbool.h>
#include "232-implement-queue-using-stacks.h"

MyQueue* myQueueCreate() {
    MyQueue * p = malloc(sizeof *p);
    p->bag = malloc(sizeof *p->bag);
    p->bag->top = 0;
    p->bag->val = malloc(sizeof *p->bag->val * STACK_MAX_SIZE);
    p->stash = malloc(sizeof *p->stash);
    p->stash->top = 0;
    p->stash->val = malloc(sizeof *p->stash->val * STACK_MAX_SIZE);
    return p;
}

static void stash (MyQueue * obj) {
    while (obj->bag->top)
        obj->stash->val[obj->stash->top++] = obj->bag->val[--obj->bag->top];
}

static void fetch (MyQueue * obj) {
    while (obj->stash->top)
        obj->bag->val[obj->bag->top++] = obj->stash->val[--obj->stash->top];
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->bag->top == STACK_MAX_SIZE)
        return;

    stash(obj);
    obj->bag->val[obj->bag->top++] = x;
    fetch(obj);

    return;
}

int myQueuePop(MyQueue* obj) {
    return obj->bag->val[--obj->bag->top];
}

int myQueuePeek(MyQueue* obj) {
    return obj->bag->val[obj->bag->top - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return !obj->bag->top;
}

void myQueueFree(MyQueue* obj) {
    free(obj->bag->val);
    free(obj->bag);
    free(obj->stash->val);
    free(obj->stash);
    free(obj);

    return;
}
