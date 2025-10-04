#ifndef DFS_GRAPH_LIST_H
#define DFS_GRAPH_LIST_H

#include <stddef.h>

// Adjacency list representation: array of arrays
// Each graph[i] is a NULL-terminated array of neighbors for node i
typedef int** GraphList;

// Depth-first search on adjacency list graph
// graph: adjacency list (graph[i] is NULL-terminated array of neighbors)
// num_nodes: number of nodes in the graph
// source: starting node
// needle: target value to find
// path: output array to store the path (must be pre-allocated)
// path_len: output parameter for path length
// Returns true if path found, false otherwise
bool dfs_graph_list(GraphList graph, size_t num_nodes, int source, int needle,
                   int *path, size_t *path_len);

#endif // DFS_GRAPH_LIST_H
