#include "queue.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    Queue *q = queue_create();
    ASSERT_BOOL_EQ(q != NULL, true, "Create queue");
    queue_destroy(q);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy queue" COLOR_RESET "\n");
}

void test_enqueue_dequeue(void) {
    Queue *q = queue_create();
    queue_enqueue(q, 42);
    ASSERT_INT_EQ(queue_dequeue(q), 42, "Enqueue and dequeue");
    queue_destroy(q);
}

void test_fifo_order(void) {
    Queue *q = queue_create();
    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);
    ASSERT_INT_EQ(queue_dequeue(q), 1, "FIFO first");
    ASSERT_INT_EQ(queue_dequeue(q), 2, "FIFO second");
    ASSERT_INT_EQ(queue_dequeue(q), 3, "FIFO third");
    queue_destroy(q);
}

void test_is_empty(void) {
    Queue *q = queue_create();
    ASSERT_BOOL_EQ(queue_is_empty(q), true, "Empty initially");
    queue_enqueue(q, 1);
    ASSERT_BOOL_EQ(queue_is_empty(q), false, "Not empty after enqueue");
    queue_dequeue(q);
    ASSERT_BOOL_EQ(queue_is_empty(q), true, "Empty after dequeue");
    queue_destroy(q);
}

void test_size(void) {
    Queue *q = queue_create();
    ASSERT_INT_EQ(queue_size(q), 0, "Initial size");
    queue_enqueue(q, 1);
    ASSERT_INT_EQ(queue_size(q), 1, "Size after enqueue");
    queue_enqueue(q, 2);
    ASSERT_INT_EQ(queue_size(q), 2, "Size after second enqueue");
    queue_dequeue(q);
    ASSERT_INT_EQ(queue_size(q), 1, "Size after dequeue");
    queue_destroy(q);
}

void test_peek(void) {
    Queue *q = queue_create();
    queue_enqueue(q, 42);
    ASSERT_INT_EQ(queue_peek(q), 42, "Peek value");
    ASSERT_INT_EQ(queue_peek(q), 42, "Peek doesn't remove");
    queue_destroy(q);
}

int main(void) {
    printf(COLOR_BOLD "Running queue tests:\n" COLOR_RESET);

    test_create_destroy();
    test_enqueue_dequeue();
    test_fifo_order();
    test_is_empty();
    test_size();
    test_peek();

    PRINT_TEST_SUMMARY("queue");
    return test_failed > 0 ? 1 : 0;
}
