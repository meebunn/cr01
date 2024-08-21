#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int num;
    struct AdjList* array;
};

struct Node* newNode(int vertex) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

struct Graph* initGraph(int num) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num = num;

    graph->array = (struct AdjList*)malloc(num * sizeof(struct AdjList));

    for (int i = 0; i < num; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* node = newNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;
}

void DFS(struct Graph* graph, int v, bool visited[], struct Node* stack) {
    visited[v] = true;
    struct Node* adjList = graph->array[v].head;

    while (adjList) {
        int vertex = adjList->vertex;
        if (!visited[vertex]) {
            DFS(graph, vertex, visited, stack);
        }
        adjList = adjList->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = stack->next;
    stack->next = newNode;
}

struct Graph* tsp(struct Graph* graph) {
    struct Graph* transposed = initGraph(graph->num);

    for (int v = 0; v < graph->num; v++) {
        struct Node* adjList = graph->array[v].head;
        while (adjList) {
            addEdge(transposed, adjList->vertex, v);
            adjList = adjList->next;
        }
    }

    return transposed;
}

void printSorted(struct Node* head) {
    int vertices[1000];
    int count = 0;

    struct Node* crr = head->next;
    while (crr) {
        vertices[count++] = crr->vertex;
        crr = crr->next;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (vertices[i] > vertices[j]) {
                int temp = vertices[i];
                vertices[i] = vertices[j];
                vertices[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", vertices[i]);
    }
    printf("\n");
}

void findLargest(struct Graph* graph) {
    int num = graph->num;
    bool visited[num];
    for (int i = 0; i < num; i++) {
        visited[i] = false;
    }

    struct Node* stack = (struct Node*)malloc(sizeof(struct Node));
    stack->next = NULL;

    for (int i = 0; i < num; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack);
        }
    }

    struct Graph* tspGraph = tsp(graph);

    for (int i = 0; i < num; i++) {
        visited[i] = false;
    }

    int LS = 0;
    struct Node* LH = NULL;

    while (stack->next) {
        int v = stack->next->vertex;
        stack->next = stack->next->next;

        if (!visited[v]) {
            struct Node* headcomp = (struct Node*)malloc(sizeof(struct Node));
            headcomp->next = NULL;

            DFS(tspGraph, v, visited, headcomp);

            int componentSize = 0;
            struct Node* crr = headcomp->next;
            while (crr) {
                componentSize++;
                crr = crr->next;
            }

            if (componentSize > LS) {
                LS = componentSize;
                struct Node* temp = LH;
                while (temp) {
                    struct Node* next = temp->next;
                    free(temp);
                    temp = next;
                }
                LH = headcomp;
            } else {
                struct Node* temp = headcomp;
                while (temp) {
                    struct Node* next = temp->next;
                    free(temp);
                    temp = next;
                }
            }
        }
    }
    printSorted(LH);
}

int main() {
    int num, edges;
    int a, b;
    scanf("%d %d", &num, &edges);
    struct Graph* graph = initGraph(num);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &a, &b);
        addEdge(graph, a, b);
    }
    findLargest(graph);
    return 0;
}

/*
10 14
0 1
0 4
2 0
2 9
3 2
5 3
5 7
6 1
6 7
7 8
7 0
8 4
8 6
9 5
*/