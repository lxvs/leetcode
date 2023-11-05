#include <stdlib.h>
#include "701-insert-into-a-binary-tree.h"

struct TreeNode * insertIntoBST (struct TreeNode * root, int val) {
    struct TreeNode * p = root;

    if (root == NULL) {
        root = malloc (sizeof *root);
        root->val = val;
        root->left = root->right = NULL;
        return root;
    }

    while (p != NULL && ((val < p->val && p->left != NULL) || (val > p->val && p->right != NULL))) {
        p = (val < p->val) ? p->left : p->right;
    }

    if (val < p->val) {
        p->left = malloc (sizeof *p->left);
        p->left->val = val;
        p->left->left = p->left->right = NULL;
    } else {
        p->right = malloc (sizeof *p->right);
        p->right->val = val;
        p->right->left = p->right->right = NULL;
    }

    return root;
}
