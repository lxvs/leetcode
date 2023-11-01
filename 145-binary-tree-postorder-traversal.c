#include <stdlib.h>
#include <lib/btree.h>

static void traverse(struct TreeNode * root, int * array, int * returnSize) {
    if (!root)
        return;
    traverse(root->left, array, returnSize);
    traverse(root->right, array, returnSize);
    array[(*returnSize)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * postorderTraversal(struct TreeNode * root, int * returnSize) {
    int * ret = malloc(sizeof *ret * 100);
    *returnSize = 0;
    traverse(root, ret, returnSize);
    return ret;
}
