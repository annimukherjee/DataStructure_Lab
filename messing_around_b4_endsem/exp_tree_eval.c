#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent the nodes of the expression tree
typedef struct Node
{
    char info[10];
    struct Node *left, *right;
} Node;

// Function to create a new node
Node *newNode(char *value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->info, value);
    temp->left = temp->right = NULL;
    return temp;
}

// Utility function to return the integer value of a given string
int toInt(char *s)
{
    int num = 0;
    int sign = 1;
    int start = 0;

    // Check for negative sign
    if (s[0] == '-')
    {
        sign = -1;
        start = 1;
    }

    // Convert string to integer
    for (int i = start; s[i] != '\0'; i++)
    {
        num = num * 10 + (s[i] - '0');
    }

    return num * sign;
}

// Function to recursively evaluate the expression tree
int eval(Node *root)
{
    if (!root)
        return 0;

    // Leaf node
    if (!root->left && !root->right)
        return toInt(root->info);

    // Evaluate left and right subtrees
    int l_val = eval(root->left);
    int r_val = eval(root->right);

    // Apply the appropriate operator
    if (strcmp(root->info, "+") == 0)
        return l_val + r_val;
    if (strcmp(root->info, "-") == 0)
        return l_val - r_val;
    if (strcmp(root->info, "*") == 0)
        return l_val * r_val;
    if (strcmp(root->info, "/") == 0)
        return l_val / r_val;

    return 0;
}

// Main driver function
int main()
{
    // Construct the expression tree
    Node *root = newNode("+");
    root->left = newNode("*");
    root->left->left = newNode("5");
    root->left->right = newNode("-4");
    root->right = newNode("-");
    root->right->left = newNode("100");
    root->right->right = newNode("20");

    printf("%d\n", eval(root));

    // Clean up the tree
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    // Construct another tree and evaluate
    root = newNode("+");
    root->left = newNode("*");
    root->left->left = newNode("5");
    root->left->right = newNode("4");
    root->right = newNode("-");
    root->right->left = newNode("100");
    root->right->right = newNode("/");
    root->right->right->left = newNode("20");
    root->right->right->right = newNode("2");

    printf("%d", eval(root));

    // Clean up
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right->left);
    free(root->right->right->right);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
