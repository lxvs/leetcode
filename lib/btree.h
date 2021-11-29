#ifndef __BTREE_H__
#define __BTREE_H__

typedef struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
} tree_t;

tree_t * NewNode (int val);

#endif // __BTREE_H__
