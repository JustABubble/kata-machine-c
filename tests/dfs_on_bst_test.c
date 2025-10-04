#include "dfs_on_bst.h"
#include "test_helpers.h"

void test_empty_tree(void) {
    bool result = dfs_on_bst(NULL, 42);
    ASSERT_BOOL_EQ(result, false, "Empty tree");
}

void test_single_node_found(void) {
    BSTNode root = {.val = 42, .left = NULL, .right = NULL};
    bool result = dfs_on_bst(&root, 42);
    ASSERT_BOOL_EQ(result, true, "Single node found");
}

void test_single_node_not_found(void) {
    BSTNode root = {.val = 42, .left = NULL, .right = NULL};
    bool result = dfs_on_bst(&root, 7);
    ASSERT_BOOL_EQ(result, false, "Single node not found");
}

void test_valid_bst_found(void) {
    //      10
    //     /  \
    //    5   15
    //   / \
    //  3   7
    BSTNode nodes[5] = {
        {.val = 10, .left = &nodes[1], .right = &nodes[2]},
        {.val = 5, .left = &nodes[3], .right = &nodes[4]},
        {.val = 15, .left = NULL, .right = NULL},
        {.val = 3, .left = NULL, .right = NULL},
        {.val = 7, .left = NULL, .right = NULL}
    };
    bool result = dfs_on_bst(&nodes[0], 7);
    ASSERT_BOOL_EQ(result, true, "Valid BST found");
}

void test_valid_bst_not_found(void) {
    BSTNode nodes[5] = {
        {.val = 10, .left = &nodes[1], .right = &nodes[2]},
        {.val = 5, .left = &nodes[3], .right = &nodes[4]},
        {.val = 15, .left = NULL, .right = NULL},
        {.val = 3, .left = NULL, .right = NULL},
        {.val = 7, .left = NULL, .right = NULL}
    };
    bool result = dfs_on_bst(&nodes[0], 99);
    ASSERT_BOOL_EQ(result, false, "Valid BST not found");
}

void test_left_skewed(void) {
    BSTNode nodes[3] = {
        {.val = 10, .left = &nodes[1], .right = NULL},
        {.val = 5, .left = &nodes[2], .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    bool result = dfs_on_bst(&nodes[0], 3);
    ASSERT_BOOL_EQ(result, true, "Left skewed found");
}

void test_right_skewed(void) {
    BSTNode nodes[3] = {
        {.val = 10, .left = NULL, .right = &nodes[1]},
        {.val = 15, .left = NULL, .right = &nodes[2]},
        {.val = 20, .left = NULL, .right = NULL}
    };
    bool result = dfs_on_bst(&nodes[0], 20);
    ASSERT_BOOL_EQ(result, true, "Right skewed found");
}

int main(void) {
    printf(COLOR_BOLD "Running dfs_on_bst tests:\n" COLOR_RESET);

    test_empty_tree();
    test_single_node_found();
    test_single_node_not_found();
    test_valid_bst_found();
    test_valid_bst_not_found();
    test_left_skewed();
    test_right_skewed();

    PRINT_TEST_SUMMARY("dfs_on_bst");
    return test_failed > 0 ? 1 : 0;
}
