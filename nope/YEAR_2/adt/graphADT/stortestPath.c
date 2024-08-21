#include <stdio.h>
#define MAX_VERTICES 100
#define INFINITY 1000000

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

void AddEdge(Graph *graph, int u, int v, int weight) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
    graph->weight[u][v] = weight;
    graph->weight[v][u] = weight;
}

int mindist(int dist[], int sptSet[], int vertex) {
    int min = INFINITY, min_index;

    for (int v = 0; v < vertex; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void res(Graph *graph, int start, int end) {
    int vertex = graph->vertex;
    int dist[vertex];
    int sptSet[vertex];

    for (int i = 0; i < vertex; i++) {
        dist[i] = INFINITY;
        sptSet[i] = 0; 
    }

    dist[start] = 0;

    for (int c = 0; c < vertex - 1; c++) {
        int u = mindist(dist, sptSet, vertex);
        sptSet[u] = 1; 

        for (int v = 0; v < vertex; v++) {
            if (!sptSet[v] && graph->adj[u][v] && dist[u] != INFINITY && dist[u] + graph->weight[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->weight[u][v];
            }
        }
    }

    printf("%d\n", (dist[end] == INFINITY) ? -1 : dist[end]);
}

int main() {
    Graph graph;
    int vertex, edges,round;
    scanf("%d %d %d", &vertex, &edges,&round);
    initGraph(&graph, vertex);

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        AddEdge(&graph, u, v, weight);
    }

    int start, end;
    for(int i=0 ; i<round ;i++){
        scanf("%d %d", &start, &end);
        res(&graph, start, end);
    }
    return 0;
}

/*
7 7 7
0 4 12
1 0 12
2 1 12
2 3 12
3 6 20
6 5 40
5 0 30
*/