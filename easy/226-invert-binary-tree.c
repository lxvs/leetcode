#include <stdlib.h>
#include "226-invert-binary-tree.h"

static void swap (struct TreeNode ** a, struct TreeNode ** b) {
    struct TreeNode * tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

struct TreeNode * invertTree (struct TreeNode * root) {
    if (!root)
        return NULL;
    struct TreeNode ** stack = malloc(sizeof *stack * 100);
    unsigned char top = 0;
    stack[top++] = root;

    while (top) {
        struct TreeNode * p = stack[--top];
        swap(&p->left, &p->right);
        if (p->left)
            stack[top++] = p->left;
        if (p->right)
            stack[top++] = p->right;
    }
    return root;
}
