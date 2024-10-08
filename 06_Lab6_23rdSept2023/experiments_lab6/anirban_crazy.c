#include <stdio.h>
#include <stdlib.h>
// #include<malloc.h>

struct sparse_header
{
    int nrow;
    int ncol;
    int nval;
    struct sparse_header *next;
};

struct matrix
{
    int row, col;
    int val;
    struct matrix *next;
};

typedef struct matrix NODE;
typedef struct sparse_header HEADNODE;

NODE *input();
void disp(NODE *s);

HEADNODE *metainfo;

NODE *input()
{
    NODE *start, *curr, *prev = NULL;
    int m, n, p, i;
    printf("\nEnter the number of rows, columns and non-zero values in sparse matrix: \n");
    scanf("%d%d%d", &m, &n, &p);
    // curr = (NODE *)malloc(sizeof(NODE));

    metainfo = (HEADNODE *)malloc(sizeof(HEADNODE));

    metainfo->next = NULL;
    metainfo->nrow = m;
    metainfo->ncol = n;
    metainfo->nval = p;

    start = metainfo;
    prev = metainfo;

    printf("In Enter row#, col# and non-zero value: \n");
    for (i = 1; i <= p; i++)
    {
        curr = (NODE *)malloc(sizeof(NODE));
        if (i == 1)
        {
            start = curr;
            prev = curr;
        }

        scanf("%d%d%d", &curr->row, &curr->col, &curr->val);
        curr->next = NULL;
        prev->next = curr;
        prev = curr;
        if (i == 1)
            metainfo->next = curr;
    }

    return start;
}

void disp(NODE *s)
{
    printf("\n\tSparse Matrix:\n");
    printf("\nHEADERNODE\n");
    printf("nrows: %d\n", metainfo->nrow);
    printf("ncols: %d\n", metainfo->ncol);
    printf("nvals: %d\n", metainfo->nval);
    
    
    
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