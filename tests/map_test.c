#include "map.h"
#include "test_helpers.h"

void test_create_destroy(void) {
    Map *map = map_create();
    ASSERT_BOOL_EQ(map != NULL, true, "Create map");
    map_destroy(map);
    test_passed++;
    printf("  " COLOR_GREEN "✓ Destroy map" COLOR_RESET "\n");
}

void test_put_and_get(void) {
    Map *map = map_create();
    map_put(map, 1, 100);
    map_put(map, 2, 200);
    ASSERT_INT_EQ(map_get(map, 1), 100, "Get key 1");
    ASSERT_INT_EQ(map_get(map, 2), 200, "Get key 2");
    ASSERT_INT_EQ(map_get(map, 3), -1, "Get non-existent key");
    map_destroy(map);
}

void test_update_value(void) {
    Map *map = map_create();
    map_put(map, 1, 100);
    map_put(map, 1, 200);
    ASSERT_INT_EQ(map_get(map, 1), 200, "Update value");
    ASSERT_INT_EQ(map_size(map), 1, "Size unchanged on update");
    map_destroy(map);
}

void test_contains(void) {
    Map *map = map_create();
    map_put(map, 42, 1000);
    ASSERT_BOOL_EQ(map_contains(map, 42), true, "Contains existing key");
    ASSERT_BOOL_EQ(map_contains(map, 99), false, "Contains non-existent key");
    map_destroy(map);
}

void test_remove(void) {
    Map *map = map_create();
    map_put(map, 1, 100);
    map_put(map, 2, 200);
    map_remove(map, 1);
    ASSERT_BOOL_EQ(map_contains(map, 1), false, "Key removed");
    ASSERT_INT_EQ(map_get(map, 2), 200, "Other key remains");
    ASSERT_INT_EQ(map_size(map), 1, "Size after remove");
    map_destroy(map);
}

void test_collisions(void) {
    Map *map = map_create();
    // Insert many keys to test collision handling
    for (int i = 0; i < 100; i++) {
        map_put(map, i, i * 10);
    }
    ASSERT_INT_EQ(map_size(map), 100, "Size after many inserts");
    ASSERT_INT_EQ(map_get(map, 50), 500, "Get after collisions");
    ASSERT_INT_EQ(map_get(map, 99), 990, "Get last inserted");
    map_destroy(map);
}

void test_size(void) {
    Map *map = map_create();
    ASSERT_INT_EQ(map_size(map), 0, "Initial size");
    map_put(map, 1, 100);
    ASSERT_INT_EQ(map_size(map), 1, "Size after put");
    map_put(map, 2, 200);
    ASSERT_INT_EQ(map_size(map), 2, "Size after second put");
    map_remove(map, 1);
    ASSERT_INT_EQ(map_size(map), 1, "Size after remove");
    map_destroy(map);
}

int main(void) {
    printf(COLOR_BOLD "Running map tests:\n" COLOR_RESET);

    test_create_destroy();
    test_put_and_get();
    test_update_value();
    test_contains();
    test_remove();
    test_collisions();
    test_size();

    PRINT_TEST_SUMMARY("map");
    return test_failed > 0 ? 1 : 0;
}
