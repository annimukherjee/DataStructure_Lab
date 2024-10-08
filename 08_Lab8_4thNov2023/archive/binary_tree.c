// write a menu driven program to implement the binary tree with the option - insertion, preorder traversal, inorder traversal, , postorder traversal, exit.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *root = NULL;
NODE *insert(NODE *tree, int num);
void preorder(NODE *tree);
void inorder(NODE *tree);
void postorder(NODE *tree);
int count = 1;
void main()
{
    int choice, num;
    do
    {
        printf("\n 1.INSERT \n 2.PREORDER \n 3.INORDER \n 4.POSTORDER \n 5.EXIT");
        printf("\n Enter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter item:");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            printf("\n Preorder Traversing \n");
            preorder(root);
            break;
        case 3:
            printf("\n Inorder Traversing \n");
            inorder(root);
            break;
        case 4:
            printf("\n Postorder Traversing \n");
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("\n Wrong Choice");
        }
    } while (choice != 5);
}
NODE *insert(NODE *p, int num)
{
    if (p == NULL)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->left = NULL;
        p->right = NULL;
        p->data = num;
        count++;
        ;
    }
    else if (count % 2 == 0)
        p->left = insert(p->left, num);
    else
        p->right = insert(p->right, num);
    return (p);
}

void preorder(NODE *p)
{
    if (p != NULL)
    {
        printf("%d \n", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(NODE *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d \n", p->data);
        inorder(p->right);
    }
}

void postorder(NODE *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d \n", p->data);
    }
}
