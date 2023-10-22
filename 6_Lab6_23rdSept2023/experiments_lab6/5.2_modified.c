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
    int m, n, p, i;
    printf("\nEnter the number of rows, columns and non-zero values in sparse matrix: \n");
    scanf("%d%d%d", &m, &n, &p);
    header = (NODE *)malloc(sizeof(NODE));

    header->next = NULL;
    header->row = m;
    header->col = n;
    header->val = p;

    Liststart = header;
    prev = header;

    printf("In Enter row#, col# and non-zero value: \n");
    for (i = 1; i <= p; i++)
    {
        curr = (NODE *)malloc(sizeof(NODE));
        if (i == 1)
        {
            matStart = curr;
            header->next = curr;
            prev = curr;
        }

        scanf("%d%d%d", &curr->row, &curr->col, &curr->val);
        curr->next = NULL;
        prev->next = curr;
        prev = curr;
    }

    return Liststart;
}

void disp(NODE *s)
{

    while (s != NULL)
    {
        printf("In %d %d %d \n", s->row, s->col, s->val);
        s = s->next;
    }
}

int main()
{
    NODE *spMat1 = input();
    printf("\n\n----------\ndisplaying\n----------------\n");
    disp(spMat1);
}