#include "bfs_graph_matrix.h"
#include "test_helpers.h"

void test_simple_path(void) {
    // Graph: 0 -> 1 -> 2
    int matrix[] = {
        0, 1, 0,
        0, 0, 1,
        0, 0, 0
    };

    int path[10];
    size_t path_len;
    bool result = bfs_graph_matrix(matrix, 3, 0, 2, path, &path_len);

    ASSERT_BOOL_EQ(result, true, "Simple path found");
    if (result) {
        ASSERT_BOOL_EQ(path_len > 0, true, "Path has length");
        ASSERT_INT_EQ(path[0], 0, "Path starts at source");
        ASSERT_INT_EQ(path[path_len - 1], 2, "Path ends at target");
    }
}

void test_no_path(void) {
    // Graph: 0 -> 1, 2 (disconnected)
    int matrix[] = {
        0, 1, 0,
        0, 0, 0,
        0, 0, 0
    };

    int path[10];
    size_t path_len;
    bool result = bfs_graph_matrix(matrix, 3, 0, 2, path, &path_len);

    ASSERT_BOOL_EQ(result, false, "No path exists");
}

void test_direct_edge(void) {
    // Graph: 0 -> 2
    int matrix[] = {
        0, 0, 1,
        0, 0, 0,
        0, 0, 0
    };

    int path[10];
    size_t path_len;
    bool result = bfs_graph_matrix(matrix, 3, 0, 2, path, &path_len);

    ASSERT_BOOL_EQ(result, true, "Direct edge");
    if (result) {
        ASSERT_INT_EQ(path_len, 2, "Path length is 2");
    }
}

void test_multiple_paths(void) {
    // Graph: 0 -> 1 -> 3
    //        0 -> 2 -> 3
    int matrix[] = {
        0, 1, 1, 0,
        0, 0, 0, 1,
        0, 0, 0, 1,
        0, 0, 0, 0
    };

    int path[10];
    size_t path_len;
    bool result = bfs_graph_matrix(matrix, 4, 0, 3, path, &path_len);

    ASSERT_BOOL_EQ(result, true, "Multiple paths (BFS finds shortest)");
    if (result) {
        ASSERT_INT_EQ(path_len, 3, "Shortest path length");
    }
}

void test_self_loop(void) {
    // Graph: 0 -> 0
    int matrix[] = {1};

    int path[10];
    size_t path_len;
    bool result = bfs_graph_matrix(matrix, 1, 0, 0, path, &path_len);

    ASSERT_BOOL_EQ(result, true, "Self loop");
}

int main(void) {
    printf(COLOR_BOLD "Running bfs_graph_matrix tests:\n" COLOR_RESET);

    test_simple_path();
    test_no_path();
    test_direct_edge();
    test_multiple_paths();
    test_self_loop();

    PRINT_TEST_SUMMARY("bfs_graph_matrix");
    return test_failed > 0 ? 1 : 0;
}
