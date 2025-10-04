#include "bubble_sort.h"
#include "test_helpers.h"

void test_empty_array(void) {
    int arr[] = {};
    bubble_sort(arr, 0);
    // Should not crash - just mark as passed
    test_passed++;
    printf("  " COLOR_GREEN "✓ Empty array" COLOR_RESET "\n");
}

void test_single_element(void) {
    int arr[] = {42};
    int expected[] = {42};
    bubble_sort(arr, 1);
    ASSERT_ARRAY_EQ(arr, expected, 1, "Single element");
}

void test_already_sorted(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    bubble_sort(arr, 5);
    ASSERT_ARRAY_EQ(arr, expected, 5, "Already sorted");
}

void test_reverse_sorted(void) {
    int arr[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    bubble_sort(arr, 5);
    ASSERT_ARRAY_EQ(arr, expected, 5, "Reverse sorted");
}

void test_random_order(void) {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int expected[] = {1, 1, 2, 3, 4, 5, 6, 9};
    bubble_sort(arr, 8);
    ASSERT_ARRAY_EQ(arr, expected, 8, "Random order");
}

void test_duplicates(void) {
    int arr[] = {3, 3, 3, 1, 1, 2};
    int expected[] = {1, 1, 2, 3, 3, 3};
    bubble_sort(arr, 6);
    ASSERT_ARRAY_EQ(arr, expected, 6, "Duplicates");
}

void test_negative_numbers(void) {
    int arr[] = {-5, 3, -1, 0, 2, -3};
    int expected[] = {-5, -3, -1, 0, 2, 3};
    bubble_sort(arr, 6);
    ASSERT_ARRAY_EQ(arr, expected, 6, "Negative numbers");
}

int main(void) {
    printf(COLOR_BOLD "Running bubble_sort tests:\n" COLOR_RESET);

    test_empty_array();
    test_single_element();
    test_already_sorted();
    test_reverse_sorted();
    test_random_order();
    test_duplicates();
    test_negative_numbers();

    PRINT_TEST_SUMMARY("bubble_sort");
    return test_failed > 0 ? 1 : 0;
}
