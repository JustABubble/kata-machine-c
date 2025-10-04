#include "bt_pre_order.h"
#include "test_helpers.h"

void test_empty_tree(void) {
    int result[10];
    size_t index = 0;
    bt_pre_order(NULL, result, &index);
    ASSERT_INT_EQ(index, 0, "Empty tree");
}

void test_single_node(void) {
    BinaryTreeNode root = {.val = 42, .left = NULL, .right = NULL};
    int result[10];
    size_t index = 0;
    bt_pre_order(&root, result, &index);
    int expected[] = {42};
    ASSERT_ARRAY_EQ(result, expected, index, "Single node");
}

void test_full_tree(void) {
    BinaryTreeNode nodes[7] = {
        {.val = 1, .left = &nodes[1], .right = &nodes[2]},
        {.val = 2, .left = &nodes[3], .right = &nodes[4]},
        {.val = 3, .left = &nodes[5], .right = &nodes[6]},
        {.val = 4, .left = NULL, .right = NULL},
        {.val = 5, .left = NULL, .right = NULL},
        {.val = 6, .left = NULL, .right = NULL},
        {.val = 7, .left = NULL, .right = NULL}
    };
    int result[10];
    size_t index = 0;
    bt_pre_order(&nodes[0], result, &index);
    int expected[] = {1, 2, 4, 5, 3, 6, 7};
    ASSERT_ARRAY_EQ(result, expected, 7, "Full tree");
}

void test_left_skewed(void) {
    BinaryTreeNode nodes[3] = {
        {.val = 1, .left = &nodes[1], .right = NULL},
        {.val = 2, .left = &nodes[2], .right = NULL},
        {.val = 3, .left = NULL, .right = NULL}
    };
    int result[10];
    size_t index = 0;
    bt_pre_order(&nodes[0], result, &index);
    int expected[] = {1, 2, 3};
    ASSERT_ARRAY_EQ(result, expected, 3, "Left skewed");
}

void test_right_skewed(void) {
    BinaryTreeNode nodes[3] = {
        {.val = 1, .left = NULL, .right = &nodes[1]},
        {.val = 2, .left = NULL, .right = &nodes[2]},
        {.val = 3, .left = NULL, .right = NULL}
    };
    int result[10];
    size_t index = 0;
    bt_pre_order(&nodes[0], result, &index);
    int expected[] = {1, 2, 3};
    ASSERT_ARRAY_EQ(result, expected, 3, "Right skewed");
}

int main(void) {
    printf(COLOR_BOLD "Running bt_pre_order tests:\n" COLOR_RESET);

    test_empty_tree();
    test_single_node();
    test_full_tree();
    test_left_skewed();
    test_right_skewed();

    PRINT_TEST_SUMMARY("bt_pre_order");
    return test_failed > 0 ? 1 : 0;
}
