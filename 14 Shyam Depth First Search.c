#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* adjList[MAX_NODES];
    bool visited[MAX_NODES];
};

void initializeGraph(struct Graph* graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
    }
}

void addEdge(struct Graph* graph, int source, int destination) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = graph->adjList[source];
    graph->adjList[source] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    struct Node* currentNode = graph->adjList[vertex];
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    while (currentNode != NULL) {
        int neighbor = currentNode->data;
        if (!graph->visited[neighbor]) {
            DFS(graph, neighbor);
        }
        currentNode = currentNode->next;
    }
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);

    struct Graph graph;
    initializeGraph(&graph, numNodes);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth First Traversal (starting from vertex %d):\n", startVertex);
    DFS(&graph, startVertex);

    printf("\n");

    return 0;
}
