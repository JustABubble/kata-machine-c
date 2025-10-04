#include "two_crystal_balls.h"
#include "test_helpers.h"

void test_no_breaks(void) {
    bool breaks[] = {false, false, false, false, false};
    int result = two_crystal_balls(breaks, 5);
    ASSERT_INT_EQ(result, -1, "No breaks");
}

void test_all_break(void) {
    bool breaks[] = {true, true, true, true, true};
    int result = two_crystal_balls(breaks, 5);
    ASSERT_INT_EQ(result, 0, "All break");
}

void test_break_at_beginning(void) {
    bool breaks[] = {true, true, true, true, true};
    int result = two_crystal_balls(breaks, 5);
    ASSERT_INT_EQ(result, 0, "Break at beginning");
}

void test_break_at_end(void) {
    bool breaks[] = {false, false, false, false, true};
    int result = two_crystal_balls(breaks, 5);
    ASSERT_INT_EQ(result, 4, "Break at end");
}

void test_break_in_middle(void) {
    bool breaks[] = {false, false, true, true, true};
    int result = two_crystal_balls(breaks, 5);
    ASSERT_INT_EQ(result, 2, "Break in middle");
}

void test_large_array(void) {
    bool breaks[100];
    for (int i = 0; i < 100; i++) {
        breaks[i] = (i >= 67);
    }
    int result = two_crystal_balls(breaks, 100);
    ASSERT_INT_EQ(result, 67, "Large array");
}

void test_single_element_breaks(void) {
    bool breaks[] = {true};
    int result = two_crystal_balls(breaks, 1);
    ASSERT_INT_EQ(result, 0, "Single element breaks");
}

void test_single_element_no_break(void) {
    bool breaks[] = {false};
    int result = two_crystal_balls(breaks, 1);
    ASSERT_INT_EQ(result, -1, "Single element no break");
}

int main(void) {
    printf(COLOR_BOLD "Running two_crystal_balls tests:\n" COLOR_RESET);

    test_no_breaks();
    test_all_break();
    test_break_at_beginning();
    test_break_at_end();
    test_break_in_middle();
    test_large_array();
    test_single_element_breaks();
    test_single_element_no_break();

    PRINT_TEST_SUMMARY("two_crystal_balls");
    return test_failed > 0 ? 1 : 0;
}
