//  BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BinarySearchTree
{
    int value;
    struct BinarySearchTree *left, *right;
};

typedef struct BinarySearchTree Node;

Node *rootNode = NULL;

Node *insertNode(Node *currentNode, int val);

void traversePreOrder(Node *currentNode);
void traverseInOrder(Node *currentNode);
void traversePostOrder(Node *currentNode);

bool searchNode(Node *node, int target);
Node *deleteNode(Node *node, int target);
void destroyTree(Node *node);

int countTotalNodes(Node *node);
int countLeafNodes(Node *node);
int countInternalNodes(Node *node);

int calculateHeight(Node *node);
int findLargest(Node *node);
int findSmallest(Node *node);

int main()
{
    printf("Hello! Welcome to BST program.\n");
    int choice, num;
    do
    {
        printf("\n------------------\n1. Insert node in BST\n2. Search a node in BST\n3. Preorder Traversal in BST\n4. Inorder Traversal in BST\n5. Postorder Traversal in BST\n6. Find largest element\n7. Find smallest element\n8. Delete the element\n9. Tree Height\n10. Delete the tree\n11. Total nodes\n12. Total internal nodes\n13. Total leaf nodes\n14. Quit\n-----------------\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Item:\n");
            scanf("%d", &num);
            rootNode = insertNode(rootNode, num);
            break;
        case 2:
            printf("Enter the element to be searched:\n");
            scanf("%d", &num);
            searchNode(rootNode, num);
            break;
        case 3:
            printf("\nPreorder Traversing\n");
            traversePreOrder(rootNode);
            break;
        case 4:
            printf("\nInorder Traversal\n");
            traverseInOrder(rootNode);
            break;
        case 5:
            printf("\nPostorder Traversal\n");
            traversePostOrder(rootNode);
            break;
        case 6:
            num = findLargest(rootNode);
            printf("Largest:%d\n", num);
            break;
        case 7:
            num = findSmallest(rootNode);
            printf("Smallest:%d\n", num);
            break;
        case 8:
            printf("Enter the value to be deleted:\n");
            scanf("%d", &num);
            rootNode = deleteNode(rootNode, num);
            break;
        case 9:
            num = calculateHeight(rootNode);
            printf("Height of tree is %d\n", num);
            break;
        case 10:
            destroyTree(rootNode);
            rootNode = NULL; // Ensure rootNode is set to NULL after deletion
            break;
        case 11:
            num = countTotalNodes(rootNode);
            printf("Total number of nodes:%d\n", num);
            break;
        case 12:
            num = countInternalNodes(rootNode);
            printf("Total number of internal nodes:\n%d", num);
            break;
        case 13:
            num = countLeafNodes(rootNode);
            printf("Total number of leaf nodes:%d\n", num);
            break;
        case 14:
            exit(0);
            break;
        default:
            printf("\nWrong Input\n");
        }
    } while (choice != 14);

    return 0;
}

Node *insertNode(Node *currentNode, int val)
{
    if (currentNode == NULL)
    {
        currentNode = (Node *)malloc(sizeof(Node));
        currentNode->left = NULL;
        currentNode->right = NULL;
        currentNode->value = val;
    }

    else if (val < currentNode->value)
    {
        Node *leftNode = currentNode->left;
        leftNode = insertNode(leftNode, val);
    }

    else if (val > currentNode->value)
    {
        Node *rightNode = currentNode->right;
        rightNode = insertNode(rightNode, val);
    }

    return currentNode;
}

// ------------------------------

void traversePreOrder(Node *currentNode)
{
    // TLR
    if (currentNode != NULL)
    {
        printf("%d\n", currentNode->value);
        traversePreOrder(currentNode->left);
        traversePreOrder(currentNode->right);
    }
}

void traverseInOrder(Node *currentNode)
{
    // LTR
    if (currentNode != NULL)
    {
        traverseInOrder(currentNode->left);
        printf("%d \n", currentNode->value);
        traverseInOrder(currentNode->right);
    }
}

void traversePostOrder(Node *currentNode)
{
    // LRT
    if (currentNode != NULL)
    {
        traversePostOrder(currentNode->left);
        traversePostOrder(currentNode->right);
        printf("%d \n", currentNode->value);
    }
}

// ------------------------------

bool searchNode(Node *node, int target)
{
    if (node == NULL)
    {
        printf("%d not found.\n", target);
        return false;
    }

    if (target == (node->value))
    {
        printf("%d has been found.\n", target);
        return true;
    }

    else if (target < (node->value))
        return searchNode(node->left, target);

    else
        return searchNode(node->right, target);
}

Node *deleteNode(Node *node, int target)
{
    if (node == NULL)
    {
        printf("%d is not found.\n", target);
        return node;
    }

    if (target < node->value)
        node->left = deleteNode(node->left, target);

    else if (target > node->value)
        node->right = deleteNode(node->right, target);

    else
    {
        if (node->left == NULL)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }

        // Case 3: The node to be deleted has no right child
        else if (node->right == NULL)
        {
            Node *temp = node->left;
            free(node);
            return temp;
        }

        // Case 4: The node to be deleted has both left and right children
        // Find the minimum value in the right subtree
        Node *temp = node->right;
        while (temp->left != NULL)
            temp = temp->left;

        node->value = temp->value;
        node->right = deleteNode(node->right, temp->value);
    }

    return node;
}

void destroyTree(Node *node)
{
    if (node != NULL)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        free(node);
    }
}

// ------------------------------

int countTotalNodes(Node *node)
{
    if (node == NULL)
        return 0;

    else
        return (countTotalNodes(node->left) + countTotalNodes(node->right) + 1);
}

int countLeafNodes(Node *node)
{
    if (node == NULL)
        return 0;

    else if (node->left == NULL && node->right == NULL)
        return 1;

    else
        return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int countInternalNodes(Node *node)
{
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 0;

    else
        return countInternalNodes(node->left) + countInternalNodes(node->right) + 1;
}

// ------------------------------

int calculateHeight(Node *node)
{
    if (node == NULL)
        return 0;
    
    else
    {
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int findLargest(Node *node)
{
    while (node->right != NULL)
        node = node->right;
    
    return node->value;
}

int findSmallest(Node *node)
{
    while (node->left != NULL)
        node = node->left;
    
    return node->value;
}