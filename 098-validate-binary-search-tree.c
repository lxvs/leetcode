#include "lib/btree.h"
#include <stdbool.h>
#include <stdlib.h>

bool isValidBST (struct TreeNode * root) {
    if (!(root && (root->left || root->right)))
        return true;
    if ((root->left && root->left->val >= root->val) || (root->right && root->right->val <= root->val))
        return false;
    return isValidBST(root->left) && isValidBST(root->right);
}
