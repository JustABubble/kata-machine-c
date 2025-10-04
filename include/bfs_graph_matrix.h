#ifndef BFS_GRAPH_MATRIX_H
#define BFS_GRAPH_MATRIX_H

#include <stdbool.h>
#include <stddef.h>

// Adjacency matrix representation: 2D array (row-major)
// matrix[i * num_nodes + j] == 1 means edge from i to j
typedef int* GraphMatrix;

// Breadth-first search on adjacency matrix graph
// matrix: adjacency matrix (flattened 2D array, row-major order)
// num_nodes: number of nodes in the graph
// source: starting node
// needle: target value to find
// path: output array to store the path (must be pre-allocated)
// path_len: output parameter for path length
// Returns true if path found, false otherwise
bool bfs_graph_matrix(GraphMatrix matrix, size_t num_nodes, int source,
                     int needle, int *path, size_t *path_len);

#endif // BFS_GRAPH_MATRIX_H
