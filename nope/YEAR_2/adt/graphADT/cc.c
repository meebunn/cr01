#include <stdio.h>

#define MAX_VERTICES 100
#define INFINITY 1000000 // Define your own maximum value as infinity

typedef struct Graph {
    int vertex;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int weight[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *graph, int vertex) {
    graph->vertex = vertex;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            graph->adj[i][j] = 0;
            graph->weight[i][j] = INFINITY;
        }
    }
}

void addEdge(Graph *graph, int u, int v, int weight) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
    graph->weight[u][v] = weight;
    graph->weight[v][u] = weight;
}

int minDistance(int dist[], int sptSet[], int vertex) {
    int min = INFINITY, min_index;

    for (int v = 0; v < vertex; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printshortestpath(Graph *graph, int start, int end) {
    int vertex = graph->vertex;
    int dist[vertex];
    int sptSet[vertex];

    for (int i = 0; i < vertex; i++) {
        dist[i] = INFINITY;
        sptSet[i] = 0; // Use 0 for false
    }

    dist[start] = 0;

    for (int count = 0; count < vertex - 1; count++) {
        int u = minDistance(dist, sptSet, vertex);
        sptSet[u] = 1; // Use 1 for true

        for (int v = 0; v < vertex; v++) {
            if (!sptSet[v] && graph->adj[u][v] && dist[u] != INFINITY &&
                dist[u] + graph->weight[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->weight[u][v];
            }
        }
    }

   
        printf("%d\n", start, end, dist[end]);
}


int main() {
    Graph graph;
    int n, m, p ;
    scanf("%d %d %d", &n, &m,&p);
    initGraph(&graph, n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&graph, u, v,w);
    }

    int start, end;
    for(int i = 0; i<p ;i++){
        scanf("%d %d", &start, &end);
        printshortestpath(&graph, start, end);
    }
    return 0;
}
