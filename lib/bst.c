#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <lib/bst.h>

tree_t * NewTreeNode (int val) {
    tree_t * p = malloc(sizeof *p);
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

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
tree_t * NewTree (int nodeAmount, char ** nodes) {
    /* TODO */
    return NULL;
}

/* TODO */
tree_t * parseArgsToTree (int argc, char ** argv) {
    for (int i = 0; i < argc; i++) {
        if (strcmp (argv[i], "NULL") == 0) {
            argv[i] = NULL;
        }
    }
    return NewTree (argc, argv);
}

static void _printTree (tree_t * tree, int level) {
    if (tree == NULL) {
        return;
    }
    if (tree->right != NULL) {
        _printTree (tree->right, level + 1);
    }
    for (int i = 0; i < level; i++) {
        printf ("%6s", "");
    }
    printf ("%5d \n", tree->val);
    if (tree->left != NULL) {
        _printTree (tree->left, level + 1);
    }
}

void printTree (tree_t * tree) {
    _printTree (tree, 0);
}

void freeTree (tree_t * tree) {
    if (tree == NULL) {
        return;
    }
    freeTree (tree->left);
    freeTree (tree->right);
    free (tree);
}
