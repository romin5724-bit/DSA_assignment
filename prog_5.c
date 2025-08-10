
#include <stdio.h>
#include <stdlib.h>

#define MAXV 20

typedef struct Graph {
    int V;
    int adj[MAXV][MAXV];
} Graph;

void init_graph(Graph *g, int V){
    g->V = V;
    for(int i=0;i<V;i++) for(int j=0;j<V;j++) g->adj[i][j]=0;
}

void add_edge(Graph *g, int u, int v){
    if(u<0||v<0||u>=g->V||v>=g->V) return;
    g->adj[u][v] = g->adj[v][u] = 1;
}

void bfs(Graph *g, int s){
    int visited[MAXV]={0};
    int q[MAXV], front=0, back=0;
    visited[s]=1; q[back++]=s;
    printf("BFS: ");
    while(front<back){
        int u=q[front++];
        printf("%d ", u);
        for(int v=0; v<g->V; v++){
            if(g->adj[u][v] && !visited[v]){ visited[v]=1; q[back++]=v; }
        }
    }
    printf("\n");
}

void dfs_util(Graph *g, int u, int visited[]){
    visited[u]=1;
    printf("%d ", u);
    for(int v=0; v<g->V; v++){
        if(g->adj[u][v] && !visited[v]) dfs_util(g,v,visited);
    }
}

void dfs(Graph *g, int s){
    int visited[MAXV]={0};
    printf("DFS: ");
    dfs_util(g,s,visited);
    printf("\n");
}

int main(){
    Graph g;
    init_graph(&g,6);
    add_edge(&g,0,1); add_edge(&g,0,2);
    add_edge(&g,1,3); add_edge(&g,1,4);
    add_edge(&g,2,4); add_edge(&g,3,5);
    printf("Graph adjacency matrix (6 vertices):\n");
    for(int i=0;i<g.V;i++){
        for(int j=0;j<g.V;j++) printf("%d ", g.adj[i][j]);
        printf("\n");
    }
    bfs(&g,0);
    dfs(&g,0);
    return 0;
}