#include "lib/btree.h"

#include <stdlib.h>

static void traverse (struct TreeNode * root, int * ret, int * retsz) {
    if (!root)
        return;
    ret[(*retsz)++] = root->val;
    traverse(root->left, ret, retsz);
    traverse(root->right, ret, retsz);
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * preorderTraversal (struct TreeNode * root, int * returnSize) {
    int * ret;
    *returnSize = 0;

    if (!root)
        return NULL;

    ret = malloc(sizeof *ret * 100);

    traverse(root, ret, returnSize);

    return ret;
}
