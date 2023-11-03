#include <stdlib.h>
#include "701-insert-into-a-binary-tree.h"

struct TreeNode * insertIntoBST (struct TreeNode * root, int val) {
    if (!root) {
        root = malloc(sizeof *root);
        root->val = val;
        root->left = root->right = NULL;
        return root;
    }
    struct TreeNode * p = root;
    while (p && ((val < p->val && p->left) || (val > p->val && p->right)))
        p = val < p->val ? p->left : p->right;
    if (val < p->val) {
        p->left = malloc(sizeof *p);
        p->left->val = val;
        p->left->left = p->left->right = NULL;
    } else {
        p->right = malloc(sizeof *p);
        p->right->val = val;
        p->right->left = p->right->right = NULL;
    }
    return root;
}
