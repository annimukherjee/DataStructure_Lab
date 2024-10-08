// TAKES INPUT IN normal 2d Matrix AND DISPLAYS IT 3 TUPLE using LL in Backend

#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int row, col;
    int val;
    struct matrix *next;
};

typedef struct matrix NODE;

NODE *input();
void disp(NODE *s);

NODE *input()
{

    NODE *Liststart, *curr, *prev = NULL;
    NODE *matStart = NULL;
    NODE *header;

    int m, n, p;
    printf("\nEnter the number of rows, columns and non-zero values in sparse matrix: \n");
    scanf("%d%d%d", &m, &n, &p);
    header = (NODE *)malloc(sizeof(NODE));

    header->next = NULL;
    header->row = m;
    header->col = n;
    header->val = p;

    Liststart = header;
    prev = header;

    int *a = (int *)malloc(m * n * sizeof(int));

    int i = 0, j = 0;

    printf("input the 2d array\n");
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", (a + i * n + j));
    

    printf("Alloc 2D to LL.....\n");
    int counter = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(a + i * n + j) != 0)
            {
                counter++;
                curr = (NODE *)malloc(sizeof(NODE));
                if (counter == 1)
                {
                    matStart = curr;
                    header->next = curr;
                    prev = curr;
                }

                // scanf("%d%d%d", &curr->row, &curr->col, &curr->val);
                curr->row = i;
                curr->col = j;
                curr->val = *(a + i * n + j);

                curr->next = NULL;
                prev->next = curr;
                prev = curr;
            }
        }
    }

    printf("done...\n");
    return Liststart;
}

void disp(NODE *s)
{
    while (s != NULL)
    {
        printf("%d %d %d \n", s->row, s->col, s->val);
        s = s->next;
    }
}

int main()
{
    NODE *spMat1 = input();
    printf("\n\n----------\ndisplaying\n----------------\n");
    disp(spMat1);
}