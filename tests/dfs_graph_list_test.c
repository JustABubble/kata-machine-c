#include "dfs_graph_list.h"
#include "test_helpers.h"

void test_simple_path(void) {
    // Graph: 0 -> 1 -> 2
    int neighbors_0[] = {1, -1};
    int neighbors_1[] = {2, -1};
    int neighbors_2[] = {-1};
    int *adj_list[] = {neighbors_0, neighbors_1, neighbors_2};

    int path[10];
    size_t path_len;
    bool result = dfs_graph_list(adj_list, 3, 0, 2, path, &path_len);

    ASSERT_BOOL_EQ(result, true, "Simple path found");
    if (result) {
        ASSERT_BOOL_EQ(path_len > 0, true, "Path has length");
        ASSERT_INT_EQ(path[0], 0, "Path starts at source");
        ASSERT_INT_EQ(path[path_len - 1], 2, "Path ends at target");
    }
}

void test_no_path(void) {
    // Graph: 0 -> 1, 2 (disconnected)
    int neighbors_0[] = {1, -1};
    int neighbors_1[] = {-1};
    int neighbors_2[] = {-1};
    int *adj_list[] = {neighbors_0, neighbors_1, neighbors_2};

    int path[10];
    size_t path_len;
    bool result = dfs_graph_list(adj_list, 3, 0, 2, path, &path_len);

    ASSERT_BOOL_EQ(result, false, "No path exists");
}

void test_self_loop(void) {
    // Graph: 0 -> 0
    int neighbors_0[] = {0, -1};
    int *adj_list[] = {neighbors_0};

    int path[10];
    size_t path_len;
    bool result = dfs_graph_list(adj_list, 1, 0, 0, path, &path_len);

    ASSERT_BOOL_EQ(result, true, "Self loop");
}

void test_cycle(void) {
    // Graph: 0 -> 1 -> 2 -> 0 -> 3
    int neighbors_0[] = {1, 3, -1};
    int neighbors_1[] = {2, -1};
    int neighbors_2[] = {0, -1};
    int neighbors_3[] = {-1};
    int *adj_list[] = {neighbors_0, neighbors_1, neighbors_2, neighbors_3};

    int path[10];
    size_t path_len;
    bool result = dfs_graph_list(adj_list, 4, 0, 3, path, &path_len);

    ASSERT_BOOL_EQ(result, true, "Path in graph with cycle");
}

int main(void) {
    printf(COLOR_BOLD "Running dfs_graph_list tests:\n" COLOR_RESET);

    test_simple_path();
    test_no_path();
    test_self_loop();
    test_cycle();

    PRINT_TEST_SUMMARY("dfs_graph_list");
    return test_failed > 0 ? 1 : 0;
}
