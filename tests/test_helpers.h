#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ANSI color codes for terminal output
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_BOLD "\x1b[1m"

// Test statistics
static int test_passed = 0;
static int test_failed = 0;

// Helper to print integer arrays
static void print_int_array(const int *arr, size_t len) {
    printf("[");
    for (size_t i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Assert that two integers are equal
#define ASSERT_INT_EQ(actual, expected, test_name)                             \
    do {                                                                       \
        int _actual = (actual);                                                \
        int _expected = (expected);                                            \
        if (_actual != _expected) {                                            \
            test_failed++;                                                     \
            printf("  " COLOR_RED "✗ %s FAILED" COLOR_RESET "\n", test_name);  \
            printf("    Expected: %d\n", _expected);                           \
            printf("    Actual:   %d\n", _actual);                             \
            assert(_actual == _expected);                                      \
        } else {                                                               \
            test_passed++;                                                     \
            printf("  " COLOR_GREEN "✓ %s" COLOR_RESET "\n", test_name);       \
        }                                                                      \
    } while (0)

// Assert that two booleans are equal
#define ASSERT_BOOL_EQ(actual, expected, test_name)                            \
    do {                                                                       \
        bool _actual = (actual);                                               \
        bool _expected = (expected);                                           \
        if (_actual != _expected) {                                            \
            test_failed++;                                                     \
            printf("  " COLOR_RED "✗ %s FAILED" COLOR_RESET "\n", test_name);  \
            printf("    Expected: %s\n", _expected ? "true" : "false");        \
            printf("    Actual:   %s\n", _actual ? "true" : "false");          \
            assert(_actual == _expected);                                      \
        } else {                                                               \
            test_passed++;                                                     \
            printf("  " COLOR_GREEN "✓ %s" COLOR_RESET "\n", test_name);       \
        }                                                                      \
    } while (0)

// Assert that two integer arrays are equal
#define ASSERT_ARRAY_EQ(actual, expected, len, test_name)                      \
    do {                                                                       \
        bool _arrays_equal = true;                                             \
        size_t _len = (len);                                                   \
        for (size_t _i = 0; _i < _len; _i++) {                                 \
            if ((actual)[_i] != (expected)[_i]) {                              \
                _arrays_equal = false;                                         \
                break;                                                         \
            }                                                                  \
        }                                                                      \
        if (!_arrays_equal) {                                                  \
            test_failed++;                                                     \
            printf("  " COLOR_RED "✗ %s FAILED" COLOR_RESET "\n", test_name);  \
            printf("    Expected: ");                                          \
            print_int_array(expected, _len);                                   \
            printf("\n");                                                      \
            printf("    Actual:   ");                                          \
            print_int_array(actual, _len);                                     \
            printf("\n");                                                      \
            assert(_arrays_equal);                                             \
        } else {                                                               \
            test_passed++;                                                     \
            printf("  " COLOR_GREEN "✓ %s" COLOR_RESET "\n", test_name);       \
        }                                                                      \
    } while (0)

// Print test summary
#define PRINT_TEST_SUMMARY(test_suite_name)                                    \
    do {                                                                       \
        printf("\n" COLOR_BOLD "Test Summary for %s:" COLOR_RESET "\n",        \
               test_suite_name);                                               \
        printf("  Passed: " COLOR_GREEN "%d" COLOR_RESET "\n", test_passed);   \
        printf("  Failed: " COLOR_RED "%d" COLOR_RESET "\n", test_failed);     \
        printf("  Total:  %d\n", test_passed + test_failed);                   \
        if (test_failed == 0) {                                                \
            printf("\n" COLOR_GREEN COLOR_BOLD                                 \
                   "All tests passed! ✓" COLOR_RESET "\n");                    \
        } else {                                                               \
            printf("\n" COLOR_RED COLOR_BOLD                                   \
                   "%d test(s) failed! ✗" COLOR_RESET "\n",                    \
                   test_failed);                                               \
        }                                                                      \
    } while (0)

#endif // TEST_HELPERS_H
