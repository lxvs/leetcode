#include <lib/btree.h>
#include <stdlib.h>
#include <stdbool.h>

static bool symmetric (struct TreeNode * left, struct TreeNode * right) {
    if (!left || !right)
        return left == right;
    if (left->val != right->val)
        return false;
    return symmetric(left->left, right->right) && symmetric(left->right, right->left);
}

bool isSymmetric (struct TreeNode * root) {
    return !root || symmetric(root->left, root->right);
}
