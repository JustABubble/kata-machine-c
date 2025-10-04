#include "maze_solver.h"
#include "test_helpers.h"

// Helper to create a Point (since struct is opaque)
// Note: This is a test helper - users will implement Point in their .c file
typedef struct {
    int x;
    int y;
} TestPoint;

void test_simple_maze(void) {
    const char *maze =
        "   #"
        " # #"
        " # #"
        "    ";
    TestPoint start_data = {0, 0};
    TestPoint end_data = {3, 3};
    Point *start = (Point *)&start_data;
    Point *end = (Point *)&end_data;
    Point path[16];
    size_t path_len;

    bool result = maze_solver(maze, 4, 4, '#', *start, *end, path, &path_len);
    ASSERT_BOOL_EQ(result, true, "Simple maze solvable");

    if (result) {
        ASSERT_BOOL_EQ(path_len > 0, true, "Path has length");
        TestPoint *path_start = (TestPoint *)&path[0];
        TestPoint *path_end = (TestPoint *)&path[path_len - 1];
        ASSERT_BOOL_EQ(path_start->x == start_data.x && path_start->y == start_data.y, true,
                       "Path starts at start");
        ASSERT_BOOL_EQ(path_end->x == end_data.x && path_end->y == end_data.y, true,
                       "Path ends at end");
    }
}

void test_no_solution(void) {
    const char *maze =
        "  #"
        "# #"
        "  #";
    TestPoint start_data = {0, 0};
    TestPoint end_data = {2, 2};
    Point *start = (Point *)&start_data;
    Point *end = (Point *)&end_data;
    Point path[9];
    size_t path_len;

    bool result = maze_solver(maze, 3, 3, '#', *start, *end, path, &path_len);
    ASSERT_BOOL_EQ(result, false, "Unsolvable maze");
}

void test_direct_path(void) {
    const char *maze =
        "    "
        "    "
        "    ";
    TestPoint start_data = {0, 0};
    TestPoint end_data = {3, 2};
    Point *start = (Point *)&start_data;
    Point *end = (Point *)&end_data;
    Point path[12];
    size_t path_len;

    bool result = maze_solver(maze, 4, 3, '#', *start, *end, path, &path_len);
    ASSERT_BOOL_EQ(result, true, "Direct path exists");
}

void test_start_equals_end(void) {
    const char *maze =
        "   "
        "   "
        "   ";
    TestPoint start_data = {1, 1};
    TestPoint end_data = {1, 1};
    Point *start = (Point *)&start_data;
    Point *end = (Point *)&end_data;
    Point path[9];
    size_t path_len;

    bool result = maze_solver(maze, 3, 3, '#', *start, *end, path, &path_len);
    ASSERT_BOOL_EQ(result, true, "Start equals end");
    if (result) {
        ASSERT_INT_EQ(path_len, 1, "Path length is 1");
    }
}

int main(void) {
    printf(COLOR_BOLD "Running maze_solver tests:\n" COLOR_RESET);

    test_simple_maze();
    test_no_solution();
    test_direct_path();
    test_start_equals_end();

    PRINT_TEST_SUMMARY("maze_solver");
    return test_failed > 0 ? 1 : 0;
}
