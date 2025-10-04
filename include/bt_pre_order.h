#ifndef BT_PRE_ORDER_H
#define BT_PRE_ORDER_H

#include <stddef.h>

typedef struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// Pre-order traversal: root, left, right
// result: output array to store values
// index: pointer to current index in result array (should start at 0)
void bt_pre_order(BinaryTreeNode *root, int *result, size_t *index);

#endif // BT_PRE_ORDER_H
