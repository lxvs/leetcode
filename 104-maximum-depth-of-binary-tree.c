#include <lib/btree.h>

#define max(a, b)       (a < b ? b : a)

int maxDepth (struct TreeNode * root) {
    if (!root)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);
}
