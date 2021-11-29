#include "btree.h"
#include <stdlib.h>

tree_t * NewNode (int val) {
    tree_t * p = malloc(sizeof *p);
    p->val = val;
    p->left = p->right = NULL;
    return p;
}
