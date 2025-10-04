#include "lru.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    LRU *cache = lru_create(2);
    ASSERT_BOOL_EQ(cache != NULL, true, "Create cache");
    lru_destroy(cache);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy cache" COLOR_RESET "\n");
}

void test_put_and_get(void) {
    LRU *cache = lru_create(2);
    lru_put(cache, 1, 100);
    ASSERT_INT_EQ(lru_get(cache, 1), 100, "Get existing key");
    ASSERT_INT_EQ(lru_get(cache, 2), -1, "Get non-existing key");
    lru_destroy(cache);
}

void test_update_existing(void) {
    LRU *cache = lru_create(2);
    lru_put(cache, 1, 100);
    lru_put(cache, 1, 200);
    ASSERT_INT_EQ(lru_get(cache, 1), 200, "Update existing key");
    ASSERT_INT_EQ(lru_size(cache), 1, "Size unchanged on update");
    lru_destroy(cache);
}

void test_eviction(void) {
    LRU *cache = lru_create(2);
    lru_put(cache, 1, 100);
    lru_put(cache, 2, 200);
    lru_put(cache, 3, 300);  // Should evict key 1 (LRU)

    ASSERT_BOOL_EQ(lru_contains(cache, 1), false, "LRU evicted");
    ASSERT_BOOL_EQ(lru_contains(cache, 2), true, "Key 2 remains");
    ASSERT_BOOL_EQ(lru_contains(cache, 3), true, "Key 3 added");
    ASSERT_INT_EQ(lru_size(cache), 2, "Size at capacity");
    lru_destroy(cache);
}

void test_access_updates_recency(void) {
    LRU *cache = lru_create(2);
    lru_put(cache, 1, 100);
    lru_put(cache, 2, 200);
    lru_get(cache, 1);  // Access key 1, making it most recent
    lru_put(cache, 3, 300);  // Should evict key 2 (now LRU)

    ASSERT_BOOL_EQ(lru_contains(cache, 1), true, "Recently accessed remains");
    ASSERT_BOOL_EQ(lru_contains(cache, 2), false, "LRU evicted");
    ASSERT_BOOL_EQ(lru_contains(cache, 3), true, "New key added");
    lru_destroy(cache);
}

void test_capacity_one(void) {
    LRU *cache = lru_create(1);
    lru_put(cache, 1, 100);
    lru_put(cache, 2, 200);
    ASSERT_BOOL_EQ(lru_contains(cache, 1), false, "Capacity 1 evicts immediately");
    ASSERT_INT_EQ(lru_get(cache, 2), 200, "Latest entry remains");
    lru_destroy(cache);
}

int main(void) {
    printf(COLOR_BOLD "Running lru tests:\n" COLOR_RESET);

    test_create_destroy();
    test_put_and_get();
    test_update_existing();
    test_eviction();
    test_access_updates_recency();
    test_capacity_one();

    PRINT_TEST_SUMMARY("lru");
    return test_failed > 0 ? 1 : 0;
}
