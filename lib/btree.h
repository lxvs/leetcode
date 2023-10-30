#ifndef INCLUDED_BTREE_H_
#define INCLUDED_BTREE_H_

typedef struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
} tree_t;

tree_t * NewNode (int val);

#endif // __BTREE_H__
