

#include <stdio.h>
#include <stdlib.h>

int *addEdge(int u, int v, int *graph, int V)
{
    *(graph + u * V + v) = 1;
    *(graph + v * V + u) = 1;

    return graph;
}

int degree(int vertex, int *graph, int V)
{
    int degree = 0;
    for (int i = 0; i < V; i++)
    {
        degree += *(graph + vertex * V + i);
    }
    return degree;
}

void displayDegrees(int *graph, int V)
{
    int degrees[V];
    for (int i = 0; i < V; i++)
    {
        degrees[i] = degree(i, graph, V);
    }

    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d has degree %d\n", (i + 1), degrees[i]);
    }
}

int main()
{
    int V = 0;
    printf("Enter the number of vertex\n");
    scanf("%d", &V);

    int *graph;
    graph = (int *)malloc(sizeof(int) * V * V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            *(graph + V * i + j) = 0;
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j)
            {
                int input;
                printf("%d and %d are adjacent to eachother (0/1): ", i + 1, j + 1);
                scanf("%d", &input);
                if (input == 1)
                {
                    addEdge(i, j, graph, V);
                }
            }
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", *(graph + V * i + j));
        }
        printf("\n");
    }

    displayDegrees(graph, V);

    return 0;
}