#ifndef __BTREE_H__
#define __BTREE_H__

typedef struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
} tree_t;

#endif // __BTREE_H__
