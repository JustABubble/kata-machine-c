#include "min_heap.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    MinHeap *heap = min_heap_create();
    ASSERT_BOOL_EQ(heap != NULL, true, "Create heap");
    min_heap_destroy(heap);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy heap" COLOR_RESET "\n");
}

void test_insert_and_extract(void) {
    MinHeap *heap = min_heap_create();
    min_heap_insert(heap, 5);
    min_heap_insert(heap, 3);
    min_heap_insert(heap, 7);
    ASSERT_INT_EQ(min_heap_extract_min(heap), 3, "Extract min");
    ASSERT_INT_EQ(min_heap_extract_min(heap), 5, "Extract second min");
    ASSERT_INT_EQ(min_heap_extract_min(heap), 7, "Extract third min");
    min_heap_destroy(heap);
}

void test_peek(void) {
    MinHeap *heap = min_heap_create();
    min_heap_insert(heap, 10);
    min_heap_insert(heap, 5);
    ASSERT_INT_EQ(min_heap_peek_min(heap), 5, "Peek min");
    ASSERT_INT_EQ(min_heap_peek_min(heap), 5, "Peek doesn't remove");
    ASSERT_INT_EQ(min_heap_size(heap), 2, "Size unchanged after peek");
    min_heap_destroy(heap);
}

void test_heap_property(void) {
    MinHeap *heap = min_heap_create();
    int values[] = {9, 5, 6, 2, 3, 7, 1, 4, 8};
    for (int i = 0; i < 9; i++) {
        min_heap_insert(heap, values[i]);
    }

    // Extract all and verify they come out in sorted order
    int prev = min_heap_extract_min(heap);
    bool sorted = true;
    while (!min_heap_is_empty(heap)) {
        int curr = min_heap_extract_min(heap);
        if (curr < prev) {
            sorted = false;
            break;
        }
        prev = curr;
    }
    ASSERT_BOOL_EQ(sorted, true, "Heap property maintained");
    min_heap_destroy(heap);
}

void test_is_empty(void) {
    MinHeap *heap = min_heap_create();
    ASSERT_BOOL_EQ(min_heap_is_empty(heap), true, "Empty initially");
    min_heap_insert(heap, 1);
    ASSERT_BOOL_EQ(min_heap_is_empty(heap), false, "Not empty after insert");
    min_heap_extract_min(heap);
    ASSERT_BOOL_EQ(min_heap_is_empty(heap), true, "Empty after extract");
    min_heap_destroy(heap);
}

void test_size(void) {
    MinHeap *heap = min_heap_create();
    ASSERT_INT_EQ(min_heap_size(heap), 0, "Initial size");
    min_heap_insert(heap, 1);
    ASSERT_INT_EQ(min_heap_size(heap), 1, "Size after insert");
    min_heap_insert(heap, 2);
    ASSERT_INT_EQ(min_heap_size(heap), 2, "Size after second insert");
    min_heap_extract_min(heap);
    ASSERT_INT_EQ(min_heap_size(heap), 1, "Size after extract");
    min_heap_destroy(heap);
}

void test_duplicates(void) {
    MinHeap *heap = min_heap_create();
    min_heap_insert(heap, 5);
    min_heap_insert(heap, 5);
    min_heap_insert(heap, 5);
    ASSERT_INT_EQ(min_heap_extract_min(heap), 5, "Extract duplicate 1");
    ASSERT_INT_EQ(min_heap_extract_min(heap), 5, "Extract duplicate 2");
    ASSERT_INT_EQ(min_heap_extract_min(heap), 5, "Extract duplicate 3");
    min_heap_destroy(heap);
}

int main(void) {
    printf(COLOR_BOLD "Running min_heap tests:\n" COLOR_RESET);

    test_create_destroy();
    test_insert_and_extract();
    test_peek();
    test_heap_property();
    test_is_empty();
    test_size();
    test_duplicates();

    PRINT_TEST_SUMMARY("min_heap");
    return test_failed > 0 ? 1 : 0;
}
