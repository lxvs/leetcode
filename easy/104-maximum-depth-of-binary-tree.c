#include <stddef.h>
#include "104-maximum-depth-of-binary-tree.h"

#define MAX(a, b)       (a < b ? b : a)

int maxDepth (tree_t * root) {
    if (root == NULL) {
        return 0;
    }
    int left = maxDepth (root->left);
    int right = maxDepth (root->right);
    return 1 + MAX (left, right);
}
