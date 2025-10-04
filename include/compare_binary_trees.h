#ifndef COMPARE_BINARY_TREES_H
#define COMPARE_BINARY_TREES_H

#include <stdbool.h>

typedef struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// Check if two binary trees are structurally identical and have the same values
bool compare_binary_trees(BinaryTreeNode *a, BinaryTreeNode *b);

#endif // COMPARE_BINARY_TREES_H
