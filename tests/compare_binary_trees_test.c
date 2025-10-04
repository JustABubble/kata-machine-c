#include "compare_binary_trees.h"
#include "test_helpers.h"

void test_both_empty(void) {
    bool result = compare_binary_trees(NULL, NULL);
    ASSERT_BOOL_EQ(result, true, "Both empty");
}

void test_one_empty(void) {
    BinaryTreeNode node = {.val = 1, .left = NULL, .right = NULL};
    bool result = compare_binary_trees(&node, NULL);
    ASSERT_BOOL_EQ(result, false, "One empty");
}

void test_single_node_same(void) {
    BinaryTreeNode a = {.val = 42, .left = NULL, .right = NULL};
    BinaryTreeNode b = {.val = 42, .left = NULL, .right = NULL};
    bool result = compare_binary_trees(&a, &b);
    ASSERT_BOOL_EQ(result, true, "Single node same");
}

void test_single_node_different(void) {
    BinaryTreeNode a = {.val = 42, .left = NULL, .right = NULL};
    BinaryTreeNode b = {.val = 7, .left = NULL, .right = NULL};
    bool result = compare_binary_trees(&a, &b);
    ASSERT_BOOL_EQ(result, false, "Single node different");
}

void test_identical_trees(void) {
    BinaryTreeNode a_nodes[3] = {
        {.val = 1, .left = &a_nodes[1], .right = &a_nodes[2]},
        {.val = 2, .left = NULL, .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    BinaryTreeNode b_nodes[3] = {
        {.val = 1, .left = &b_nodes[1], .right = &b_nodes[2]},
        {.val = 2, .left = NULL, .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    bool result = compare_binary_trees(&a_nodes[0], &b_nodes[0]);
    ASSERT_BOOL_EQ(result, true, "Identical trees");
}

void test_different_structure(void) {
    BinaryTreeNode a_nodes[3] = {
        {.val = 1, .left = &a_nodes[1], .right = &a_nodes[2]},
        {.val = 2, .left = NULL, .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    BinaryTreeNode b_nodes[3] = {
        {.val = 1, .left = NULL, .right = &b_nodes[1]},
        {.val = 2, .left = &b_nodes[2], .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    bool result = compare_binary_trees(&a_nodes[0], &b_nodes[0]);
    ASSERT_BOOL_EQ(result, false, "Different structure");
}

void test_different_values(void) {
    BinaryTreeNode a_nodes[3] = {
        {.val = 1, .left = &a_nodes[1], .right = &a_nodes[2]},
        {.val = 2, .left = NULL, .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    BinaryTreeNode b_nodes[3] = {
        {.val = 1, .left = &b_nodes[1], .right = &b_nodes[2]},
        {.val = 99, .left = NULL, .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    bool result = compare_binary_trees(&a_nodes[0], &b_nodes[0]);
    ASSERT_BOOL_EQ(result, false, "Different values");
}

int main(void) {
    printf(COLOR_BOLD "Running compare_binary_trees tests:\n" COLOR_RESET);

    test_both_empty();
    test_one_empty();
    test_single_node_same();
    test_single_node_different();
    test_identical_trees();
    test_different_structure();
    test_different_values();

    PRINT_TEST_SUMMARY("compare_binary_trees");
    return test_failed > 0 ? 1 : 0;
}
