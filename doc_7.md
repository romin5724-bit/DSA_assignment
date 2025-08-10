# Documentation for prog_7.c

## Data Structures
- An adjacency matrix graph[V][V] is provided. `INF` means not reachable at first.

## Functions
- `minDistance` - chooses next vertex with minimum tentative distance, that is not in SPT
- `dijkstra`- the standard Dijkstra's algorithm, it updates `dist[]`.


## main()
- Contains a sample weighted graph (a classic example) and runs Dijkstra from source 0.

## Sample Output
```
Vertex    Distance from source 0
0         0
1         7
2         9
3         20
4         20
5         11
```