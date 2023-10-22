// TAKES INPUT IN 3 TUPLE AND DISPLAYS IT 3 TUPLE

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
    printf("\nEnter the number of rows and columns:\n");
    scanf("%d %d", &m, &n);
    header = (NODE *)malloc(sizeof(NODE));

    header->next = NULL;
    header->row = m;
    header->col = n;

    Liststart = header;
    prev = header;

    int *a = (int *)malloc(m * n * sizeof(int));

    int i = 0, j = 0, c = 0;

    printf("Input the elements for the array\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", (a + i * n + j));
            if (*(a + i * n + j) != 0)
            {
                c++;
            }
        }
    }
    header->val = c;
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
    printf("\n\n----------\nDisplaying\n----------\n");
    disp(spMat1);
}