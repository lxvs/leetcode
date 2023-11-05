#include <stdlib.h>
#include "102-binary-tree-level-order-traversal.h"

int ** levelOrder (struct TreeNode * root, int * returnSize, int ** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode * q[1001];
    int head = 0;
    int tail = 0;
    int ** returnArrays = malloc (sizeof *returnArrays * 2000);
    *returnColumnSizes = malloc (sizeof **returnColumnSizes * 2000);
    q[tail++] = root;
    while ((tail - head) % 1001 != 0) {
        int sz = (*returnColumnSizes)[*returnSize] = (tail - head) % 1001;
        returnArrays[*returnSize] = malloc (sizeof **returnArrays * sz);
        for (int i = 0; i < sz; i++) {
            struct TreeNode * p = q[head++ % 1001];
            returnArrays[*returnSize][i] = p->val;
            if (p->left)
                q[tail++ % 1001] = p->left;
            if (p->right)
                q[tail++ % 1001] = p->right;
        }
        (*returnSize)++;
    }
    return returnArrays;
}
