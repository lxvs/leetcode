#include "101-symmetric-tree.h"

static bool symmetric (tree_t * left, tree_t * right) {
    if (!left || !right)
        return left == right;
    if (left->val != right->val)
        return false;
    return symmetric(left->left, right->right) && symmetric(left->right, right->left);
}

bool isSymmetric (tree_t * root) {
    return !root || symmetric(root->left, root->right);
}
