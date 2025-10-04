#include "stack.h"
#include "test_helpers.h"

void test_create_and_destroy(void) {
    Stack *s = stack_create();
    ASSERT_BOOL_EQ(s != NULL, true, "Create stack");
    stack_destroy(s);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy stack" COLOR_RESET "\n");
}

void test_is_empty(void) {
    Stack *s = stack_create();
    ASSERT_BOOL_EQ(stack_is_empty(s), true, "New stack is empty");
    stack_push(s, 42);
    ASSERT_BOOL_EQ(stack_is_empty(s), false, "Stack with element not empty");
    stack_destroy(s);
}

void test_push_and_pop(void) {
    Stack *s = stack_create();
    stack_push(s, 42);
    int val = stack_pop(s);
    ASSERT_INT_EQ(val, 42, "Push and pop");
    stack_destroy(s);
}

void test_push_multiple(void) {
    Stack *s = stack_create();
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    ASSERT_INT_EQ(stack_pop(s), 3, "Pop first (LIFO)");
    ASSERT_INT_EQ(stack_pop(s), 2, "Pop second");
    ASSERT_INT_EQ(stack_pop(s), 1, "Pop third");
    stack_destroy(s);
}

void test_peek(void) {
    Stack *s = stack_create();
    stack_push(s, 42);
    ASSERT_INT_EQ(stack_peek(s), 42, "Peek value");
    ASSERT_INT_EQ(stack_peek(s), 42, "Peek doesn't remove");
    stack_pop(s);
    stack_destroy(s);
}

void test_size(void) {
    Stack *s = stack_create();
    ASSERT_INT_EQ(stack_size(s), 0, "Initial size");
    stack_push(s, 1);
    ASSERT_INT_EQ(stack_size(s), 1, "Size after push");
    stack_push(s, 2);
    ASSERT_INT_EQ(stack_size(s), 2, "Size after second push");
    stack_pop(s);
    ASSERT_INT_EQ(stack_size(s), 1, "Size after pop");
    stack_destroy(s);
}

void test_many_operations(void) {
    Stack *s = stack_create();
    for (int i = 0; i < 100; i++) {
        stack_push(s, i);
    }
    ASSERT_INT_EQ(stack_size(s), 100, "Size after many pushes");
    for (int i = 99; i >= 0; i--) {
        int val = stack_pop(s);
        if (val != i) {
            test_failed++;
            printf("  " COLOR_RED "✗ Many operations FAILED" COLOR_RESET "\n");
            printf("    Expected: %d at iteration %d\n", i, 99 - i);
            printf("    Actual:   %d\n", val);
            stack_destroy(s);
            return;
        }
    }
    test_passed++;
    printf("  " COLOR_GREEN "✓ Many operations" COLOR_RESET "\n");
    stack_destroy(s);
}

int main(void) {
    printf(COLOR_BOLD "Running stack tests:\n" COLOR_RESET);

    test_create_and_destroy();
    test_is_empty();
    test_push_and_pop();
    test_push_multiple();
    test_peek();
    test_size();
    test_many_operations();

    PRINT_TEST_SUMMARY("stack");
    return test_failed > 0 ? 1 : 0;
}
