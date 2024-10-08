#include <stdio.h>
#include <stdlib.h>

struct sparse_header{
    int num_of_rows;
    int num_of_cols;
    int num_of_vals;
    struct sparse_header *next;
};

typedef struct sparse_header HEADNODE;

struct matrix
{
    int row, col;
    int val;
    struct matrix *next;
};
typedef struct matrix NODE;

NODE *input();
NODE *insert_end(int r, int c, int v);
void disp(NODE *s);
NODE *add(NODE *s1, NODE *s2);

NODE *input()
{
    NODE *start, *curr, *prev = NULL;
    int m, n, p, i;
    printf("\n Enter the number of rows, columns and non-zero values in sparse matrix: \n");
    scanf("%d%d%d", &m, &n, &p);
    curr = (NODE *)malloc(sizeof(NODE));
    curr->next = NULL;
    curr->row = m;
    curr->col = n;
    curr->val = p;
    start = curr;
    prev = curr;

    printf("In Enter row#, col# and non-zero value: \n");
    for (i = 1; i <= p; i++)
    {
        curr = (NODE *)malloc(sizeof(NODE));
        scanf("%d%d%d", &curr->row, &curr->col, &curr->val);
        curr->next = NULL;
        prev->next = curr;
        prev = curr;
    }
    return start;
}

NODE *add(NODE *s1, NODE *s2)
{
    NODE *curr, *prev, *t1, *t2, *t3 = NULL;
    int row1, col1, val1, row2, col2, val2, i = 0;
    t1 = s1;
    t2 = s2;
    if (t1->row != t2->row || t1->col != t2->col)
    {
        printf("\n Order Mismatch. Addition not possible \n");
        return NULL;
    }
    curr = insert_end(t1->row, t1->col, 0);
    t3 = curr;
    prev = curr;
    t1 = t1->next;
    t2 = t2->next;
    while ((t1 != NULL) && (t2 != NULL))
    {
        row1 = t1->row;
        col1 = t1->col;
        val1 = t1->val;
        row2 = t2->row;
        col2 = t2->col;
        val2 = t2->val;
        if (row1 == row2 && col1 == col2 && val1 + val2 == 0)
        {
            t1 = t1->next;
            t2 = t2->next;
            continue;
        }
        if (row1 == row2 && col1 == col2)
        {
            curr = insert_end(row1, col1, val1 + val2);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (row1 == row2 && col1 < col2)
        {
            curr = insert_end(row1, col1, val1);
            t1 = t1->next;
        }
        else if (row1 == row2 && col1 > col2)
        {
            curr = insert_end(row2, col2, val2);
            t2 = t2->next;
        }
        else if (row1 < row2)
        {
            curr = insert_end(row1, col1, val1);
            t1 = t1->next;
        }
        else if (row1 > row2)
        {
            curr = insert_end(row2, col2, val2);
            t2 = t2->next;
        }
        prev->next = curr;
        prev = curr;
        i++;
    }

    while (t1 != NULL)
    {
        curr = insert_end(t1->row, t1->col, t1->val);
        t1 = t1->next;
        prev->next = curr;
        prev = curr;
        i++;
    }
    while (t2 != NULL)
    {
        curr = insert_end(t2->row, t2->col, t2->val);
        t2 = t2->next;
        prev->next = curr;
        prev = curr;
        i++;
    }
    t3->val = i;
    return t3;
}

NODE *insert_end(int r, int c, int v)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->row = r;
    temp->col = c;
    temp->val = v;
    temp->next = NULL;
    return temp;
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
    // disp(spMat1);
    NODE *spMat2 = input();

    printf("\n--\nspMat1\n\n---");
    disp(spMat1);
    printf("\n--\nspMat2\n\n---");
    disp(spMat2);

    NODE *result = add(spMat1, spMat2);
    printf("\n\n\n");
    disp(result);
}