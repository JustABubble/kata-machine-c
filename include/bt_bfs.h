#ifndef BT_BFS_H
#define BT_BFS_H

#include <stddef.h>

typedef struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// Breadth-first search (level-order) traversal
// result: output array to store values
// index: pointer to current index in result array (should start at 0)
void bt_bfs(BinaryTreeNode *root, int *result, size_t *index);

#endif // BT_BFS_H
