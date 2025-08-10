
#include <stdio.h>
#include <limits.h>

#define INF 1000000
#define V 6

int minDistance(int dist[], int sptSet[]){
    int min = INF, min_index = -1;
    for(int v=0; v<V; v++)
        if(!sptSet[v] && dist[v] <= min){ min = dist[v]; min_index = v; }
    return min_index;
}

void dijkstra(int graph[V][V], int src){
    int dist[V], sptSet[V]={0};
    for(int i=0;i<V;i++) dist[i]=INF;
    dist[src]=0;
    for(int count=0; count<V-1; count++){
        int u = minDistance(dist, sptSet);
        if(u==-1) break;
        sptSet[u]=1;
        for(int v=0; v<V; v++){
            if(!sptSet[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex\tDistance from source %d\n", src);
    for(int i=0;i<V;i++) printf("%d \t %d\n", i, dist[i]);
}

int main(){
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14,0,2,0,9,0}
    };
    dijkstra(graph, 0);
    return 0;
}