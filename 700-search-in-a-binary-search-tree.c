#include "lib/btree.h"

struct TreeNode * searchBST (struct TreeNode * root, int val) {
    struct TreeNode * p = root;
    while(p) {
        if (val < p->val)
            p = p->left;
        else if (val > p->val)
            p = p->right;
        else
            break;
    }
    return p;
}
