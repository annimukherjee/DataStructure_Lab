#include <stdio.h>
#include <stdlib.h>

int *insertEdge(int node1, int node2, int *adjMatrix, int numVertices);
int countDegree(int node, int *adjMatrix, int numVertices);
void showDegrees(int *adjMatrix, int numVertices);

int main()
{
    int numVertices = 0;
    printf("Enter the total number of vertices\n");
    scanf("%d", &numVertices);

    int *adjMatrix;
    adjMatrix = (int *)malloc(numVertices * numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            adjMatrix[numVertices * i + j] = 0;

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (i != j)
            {
                int response;
                printf("Is there an edge between %d and %d? (0/1): ", i + 1, j + 1);
                scanf("%d", &response);
                if (response == 1)
                    insertEdge(i, j, adjMatrix, numVertices);
            }
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
            printf("%3d ", adjMatrix[numVertices * i + j]);

        printf("\n");
    }

    showDegrees(adjMatrix, numVertices);

    return 0;
}

int *insertEdge(int row, int col, int *adjMatrix, int numVertices)
{
    adjMatrix[(row * numVertices) + col] = 1;
    adjMatrix[(col * numVertices) + row] = 1;

    return adjMatrix;
}


void showDegrees(int *adjMatrix, int numVertices)
{
    int deg[numVertices];
    for (int i = 0; i < numVertices; i++)
        deg[i] = countDegree(i, adjMatrix, numVertices);

    for (int i = 0; i < numVertices; i++)
        printf("Node %d has a degree of %d\n", i + 1, deg[i]);

}

int countDegree(int rownum, int *adjMatrix, int numVertices)
{
    int deg = 0;
    for (int i = 0; i < numVertices; i++)
        deg += adjMatrix[rownum * numVertices + i];

    return deg;
}
