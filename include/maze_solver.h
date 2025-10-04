#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <stdbool.h>
#include <stddef.h>

// Point structure for maze coordinates (implement in .c file)
typedef struct Point Point;

// Solve a maze using recursive backtracking
// maze: 2D array represented as 1D (row-major order)
// width, height: dimensions of the maze
// wall: character representing walls (e.g., '#')
// start, end: starting and ending points
// path: output array to store the path (must be pre-allocated)
// path_len: output parameter for path length
// Returns true if path found, false otherwise
bool maze_solver(const char *maze, size_t width, size_t height, char wall,
                 Point start, Point end, Point *path, size_t *path_len);

#endif // MAZE_SOLVER_H
