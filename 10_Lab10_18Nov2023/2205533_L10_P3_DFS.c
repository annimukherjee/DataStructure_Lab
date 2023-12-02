#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int vertexCount;
    int **adjacencyMatrix;
} SimpleGraph;

SimpleGraph *init_graph(int vertexCount);
void connect_vertices(SimpleGraph *graph, int v1, int v2);
void display_vertex_degrees(SimpleGraph *graph);
void depth_first_search(SimpleGraph *graph, int startVertex);

int main()
{
    int vertices, edges;
    printf("Number of vertices: ");
    scanf("%d", &vertices);

    printf("Number of edges: ");
    scanf("%d", &edges);

    SimpleGraph *graph = init_graph(vertices);

    int v1, v2;
    printf("Enter edges as vertex pairs: ");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &v1, &v2);
        connect_vertices(graph, v1, v2);
    }

    display_vertex_degrees(graph);

    printf("Starting vertex for DFS: ");
    scanf("%d", &v1);
    
    depth_first_search(graph, v1);
    return 0;
}

SimpleGraph *init_graph(int vertexCount)
{
    SimpleGraph *graph = (SimpleGraph *)malloc(sizeof(SimpleGraph));
    graph->vertexCount = vertexCount;
    graph->adjacencyMatrix = (int **)malloc(vertexCount * sizeof(int *));
    for (int i = 0; i < vertexCount; i++)
    {
        graph->adjacencyMatrix[i] = (int *)calloc(vertexCount, sizeof(int));
    }
    return graph;
}

void connect_vertices(SimpleGraph *graph, int v1, int v2)
{
    graph->adjacencyMatrix[v1][v2] = 1;
    graph->adjacencyMatrix[v2][v1] = 1;
}

void display_vertex_degrees(SimpleGraph *graph)
{
    printf("Vertex Degrees: ");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        int deg = 0;

        for (int j = 0; j < graph->vertexCount; j++)
            deg += graph->adjacencyMatrix[i][j];

        printf("%3d ", deg);
    }

    printf("\n");
}

void depth_first_search(SimpleGraph *graph, int startVertex)
{
    static int *visited = NULL;
    if (!visited)
        visited = (int *)calloc(graph->vertexCount, sizeof(int));

    visited[startVertex] = 1;
    printf("%d ", startVertex);

    for (int i = 0; i < graph->vertexCount; i++)
    {
        if (graph->adjacencyMatrix[startVertex][i] && !visited[i])
            depth_first_search(graph, i);
    }
}