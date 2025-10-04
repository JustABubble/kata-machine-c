#ifndef DFS_ON_BST_H
#define DFS_ON_BST_H

#include <stdbool.h>

typedef struct BSTNode {
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Depth-first search on a binary search tree
// Returns true if the target value is found, false otherwise
bool dfs_on_bst(BSTNode *root, int target);

#endif // DFS_ON_BST_H
