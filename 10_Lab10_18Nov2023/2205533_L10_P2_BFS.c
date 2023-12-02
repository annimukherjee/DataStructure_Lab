#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int vertices;
    int **adjMatrix;
} Graph;

Graph *initialize_graph(int vertices);
void insert_edge(Graph *graph, int u, int v);
void show_vertex_degrees(Graph *graph);
void breadth_first_search(Graph *graph, int startVertex);

int main()
{
    int vertices, edges;
    printf("Input the number of vertices: ");
    scanf("%d", &vertices);

    printf("Input the number of edges: ");
    scanf("%d", &edges);

    Graph *graph = initialize_graph(vertices);

    int u, v;
    printf("Input edges as vertex pairs: ");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        insert_edge(graph, u, v);
    }

    show_vertex_degrees(graph);

    printf("Choose the starting vertex for BFS: ");
    scanf("%d", &u);

    breadth_first_search(graph, u);

    return 0;
}

Graph *initialize_graph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;
    }
    return graph;
}


void insert_edge(Graph *graph, int u, int v)
{
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}


void show_vertex_degrees(Graph *graph)
{
    printf("Degrees of vertices: ");
    for (int i = 0; i < graph->vertices; i++)
    {
        int deg = 0;
        for (int j = 0; j < graph->vertices; j++)
            deg += graph->adjMatrix[i][j];

        printf("%d ", deg);
    }
    printf("\n");
}

void breadth_first_search(Graph *graph, int startVertex)
{
    int *visited = (int *)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = 0;


    int *queue = (int *)malloc(graph->vertices * sizeof(int));
    int front = 0, rear = 0;
    
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < graph->vertices; i++)
        {
            if (graph->adjMatrix[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}