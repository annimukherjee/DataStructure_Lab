// 2205533_L8_P3_BinTree_w_LL

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} t_node;

t_node *root = NULL;

t_node *InsertNode(t_node *rootNode, int value);
t_node *CreateNewNode(int value);
void f_preOrder(t_node *currentNode);
void f_inOrder(t_node *currentNode);
void f_postOrder(t_node *currentNode);

int main()
{
    int userSelection, inputValue;
    do
    {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\nEnter choice:\n");
        scanf("%d", &userSelection);
        switch (userSelection)
        {
        case 1:
            printf("\nEnter Value:\n");
            scanf("%d", &inputValue);
            root = InsertNode(root, inputValue);
            break;

        case 2:
            printf("\nPreorder Traversing\n");
            f_preOrder(root);
            break;

        case 3:
            printf("\nInorder Traversal\n");
            f_inOrder(root);
            break;

        case 4:
            printf("\nPostorder Traversal\n");
            f_postOrder(root);
            break;

        case 5:
            exit(0);
        default:
            printf("\nInvalid Selection\n");
        }
    } while (userSelection != 5);
    return 0;
}

t_node *CreateNewNode(int value)
{
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = value;
    return newNode;
}

t_node *InsertNode(t_node *currNode, int value)
{
    static int nodeCount = 1;
    if (currNode == NULL)
    {
        currNode = CreateNewNode(value);
        nodeCount++;
    }
    else if (nodeCount % 2 == 0)
    {
        currNode->leftChild = InsertNode(currNode->leftChild, value);
    }
    else
    {
        currNode->rightChild = InsertNode(currNode->rightChild, value);
    }
    return currNode;
}

void f_preOrder(t_node *currNode)
{
    if (currNode != NULL)
    {
        printf("%d\n", currNode->value);
        f_preOrder(currNode->leftChild);
        f_preOrder(currNode->rightChild);
    }
}

void f_inOrder(t_node *currNode)
{
    if (currNode != NULL)
    {
        f_inOrder(currNode->leftChild);
        printf("%d \n", currNode->value);
        f_inOrder(currNode->rightChild);
    }
}

void f_postOrder(t_node *currNode)
{
    if (currNode != NULL)
    {
        f_postOrder(currNode->leftChild);
        f_postOrder(currNode->rightChild);
        printf("%d \n", currNode->value);
    }
}
