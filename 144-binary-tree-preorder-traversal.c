#include <lib/btree.h>

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * preorderTraversal (struct TreeNode * root, int * returnSize) {
    struct TreeNode * t;
    struct TreeNode ** stack;
    int top = -1;
    int * ret;
    *returnSize = 0;

    if (!root)
        return NULL;

    ret = malloc(sizeof *ret * 100);
    stack = malloc(sizeof *stack * 100);
    stack[++top] = root;
    while (top > -1) {
        t = stack[top--];
        ret[(*returnSize)++] = t->val;
        if (t->right)
            stack[++top] = t->right;
        if (t->left)
            stack[++top] = t->left;
    }

    free(stack);
    return ret;
}
