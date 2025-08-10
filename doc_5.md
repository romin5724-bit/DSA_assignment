# Documentation for prog_5.c

## Data structures
- The `Graph` structure includes a number of vertices, `V`, and an adjacency matrix `adj[V][V]` consisting of 0 and 1 entries.

## Functions
- `init_graph(Graph*, int V)` - Initializes the adjacency matrix to all 0's.
- `add_edge(Graph*, int u, int v)` - Adds an undirected edge in the adjacency matrix by setting `adj[u][v]` and `adj[v][u]` to 1.
- `bfs(Graph*, int s)` - Breadth first search implemented with a pretty simple array queue.
- `dfs(Graph*, int s)` - Depth first search implemented using recursion.

## main()
- Constructs a sample graph with six vertices, prints out the adjacency matrix, and calls BFS and DFS on the graph starting at node 0.

## Sample output (abbreviated)
```
Graph adjacency matrix (6 vertices):
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 1 0
0 1 0 0 0 1
0 1 1 0 0 0
0 0 0 1 0 0

BFS: 0 1 2 3 4 5 
DFS: 0 1 3 5 4 2 
```