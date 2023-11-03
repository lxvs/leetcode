#ifndef INCLUDED_232_IMPLEMENT_QUEUE_USING_STACKS_H_
#define INCLUDED_232_IMPLEMENT_QUEUE_USING_STACKS_H_

#define STACK_MAX_SIZE      100

struct stack {
    int * val;
    int top;
};

typedef struct {
    struct stack * bag;
    struct stack * stash;
} MyQueue;

#endif  /* INCLUDED_232_IMPLEMENT_QUEUE_USING_STACKS_H_ */
