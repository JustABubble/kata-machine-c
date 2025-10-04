#ifndef BT_POST_ORDER_H
#define BT_POST_ORDER_H

#include <stddef.h>

typedef struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// Post-order traversal: left, right, root
// result: output array to store values
// index: pointer to current index in result array (should start at 0)
void bt_post_order(BinaryTreeNode *root, int *result, size_t *index);

#endif // BT_POST_ORDER_H
