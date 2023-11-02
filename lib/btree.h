#ifndef INCLUDED_BTREE_H_
#define INCLUDED_BTREE_H_

typedef struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
} tree_t;

tree_t * NewNode (int val);

/**
 * Generate a new tree based on given nodes.
 *
 * @param nodeAmount total amount of nodes, including empty ones.  Must >= 1.
 * @param nodes integers stored in a string array, use NULL to represent a empty
 *              node.  Must have at least one non-empty element.  Caller must
 *              guarantee the validity of the nodes.
 *
 * @return the generated tree.
 *
 * @note For example, to generate a tree with 4 nodes, 1, 2, 3, 4, where 1 is
 *       the root node, 2 is the left child of 1, 3 is the left child of 2, and
 *       4 is the left child of 3, the input nodes should be ["1", "2", NULL,
 *       "3", NULL, NULL, NULL, "4"], and the nodeAmount should be 8.
*/
tree_t * NewTree (int nodeAmount, char ** nodes);

tree_t * parseArgsToTree (int argc, char ** argv);

void printTree (tree_t * tree, int level);

void freeTree (tree_t * tree);

#endif  /* INCLUDED_BTREE_H_ */
