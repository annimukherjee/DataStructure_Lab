#include <stdio.h>
#include <stdlib.h>

struct CircularLinkedList
{
    int value;
    struct CircularLinkedList *nextNode;
};
typedef struct CircularLinkedList Node;

Node *head = NULL;

void createCircularLinkedList()
{
    int inputValue;
    Node *newNode, *currentNode;

    if (head == NULL)
    {
        int numberOfNodes;
        printf("Enter the number of nodes to be created:\n");
        scanf("%d", &numberOfNodes);

        head = (Node *)malloc(sizeof(Node));
        printf("Enter the data for node 0: ");
        scanf("%d", &inputValue);
        head->value = inputValue;
        head->nextNode = head;

        currentNode = head;

        for (int i = 1; i < numberOfNodes; i++)
        {
            newNode = (Node *)malloc(sizeof(Node));
            printf("Enter the data for node %d: ", i);
            scanf("%d", &inputValue);
            newNode->value = inputValue;

            newNode->nextNode = head;
            currentNode->nextNode = newNode;
            currentNode = newNode;
        }
    }
    else
    {
        printf("A list has already been created\n");
    }
}

void displayCircularLinkedList()
{
    Node *currentNode = head;
    int index = 0;
    int showMemory = 0;
    printf("\n[1]-Display with memory locations\n[0]-Display without memory locations\n-->");
    scanf("%d", &showMemory);

    if (showMemory == 0)
    {
        printf("\nThe elements in the list are:\n");
        while (currentNode->nextNode != head)
        {
            printf("Data %d: %d\n", index, currentNode->value);
            currentNode = currentNode->nextNode;
            index++;
        }
        printf("Data %d: %d\n", index, currentNode->value);
    }
    else if (showMemory == 1)
    {
        while (currentNode->nextNode != head)
        {
            printf("\nData %d: %d\n", index, currentNode->value);
            printf("\nNode %d's current memory loc: %p\n", index, currentNode);
            printf("Node %d's-->next: %p\n", index, currentNode->nextNode);
            currentNode = currentNode->nextNode;
            index++;
        }
        printf("Data %d: %d\n", index, currentNode->value);
        printf("\nNode %d's current memory loc: %p\n", index, currentNode);
        printf("Node %d's-->next: %p\n", index, currentNode->nextNode);
    }
    else
    {
        printf("Invalid Input. Only 0 or 1 is accepted.\n");
    }
}

void insertAtBeginning()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data you want to insert at beginning: ");
    scanf("%d", &newNode->value);

    newNode->nextNode = head;

    Node *tempNode = head;
    while (tempNode->nextNode != head)
    {
        tempNode = tempNode->nextNode;
    }
    tempNode->nextNode = newNode;
    head = newNode;
}

void insertAtEnd()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data you want to insert at end: ");
    scanf("%d", &newNode->value);

    Node *currentNode = head;
    while (currentNode->nextNode != head)
    {
        currentNode = currentNode->nextNode;
    }
    currentNode->nextNode = newNode;
    newNode->nextNode = head;
}

void insertAtPosition()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    int position;
    printf("Enter the data to insert: ");
    scanf("%d", &newNode->value);
    printf("Enter the position to insert at: ");
    scanf("%d", &position);

    int i = 0;
    Node *currentNode = head;
    while (i < position - 1)
    {
        currentNode = currentNode->nextNode;
        i++;
    }
    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        Node *tempNode = head;
        Node *lastNode = head;
        while (lastNode->nextNode != head)
        {
            lastNode = lastNode->nextNode;
        }
        lastNode->nextNode = head->nextNode;
        head = head->nextNode;
        printf("The element to be deleted is: %d", tempNode->value);
        free(tempNode);
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        Node *currentNode = head;
        Node *previousNode = head;
        while (currentNode->nextNode != head)
        {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
        previousNode->nextNode = head;
        printf("The element to be deleted is: %d", currentNode->value);
        free(currentNode);
    }
}

void deleteAtPosition()
{
    Node *currentNode, *nodeToDelete;
    int position;
    printf("Enter the postion at to delete at: ");
    scanf("%d", &position);
    int i = 0;
    currentNode = head;
    while (i < position - 1)
    {
        currentNode = currentNode->nextNode;
        i++;
    }
    nodeToDelete = currentNode->nextNode;
    currentNode->nextNode = nodeToDelete->nextNode;
    printf("The element to be deleted is: %d\n ", nodeToDelete->value);
    free(nodeToDelete);
}

void searchElement()
{
    Node *currentNode = head;
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int elementToSearch, index = 0, isFound = 0;
        printf("Enter the element to search: ");
        scanf("%d", &elementToSearch);
        do
        {
            if (currentNode->value == elementToSearch)
            {
                printf("The element %d was found successfully at position %d\n", elementToSearch, index);
                isFound = 1;
            }
            index++;
            currentNode = currentNode->nextNode;

        } while (currentNode != head);

        if (isFound == 0)
        {
            printf("The element was %d not found in the list\n", elementToSearch);
        }
    }
}

void countNodes()
{
    Node *currentNode = head;

    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int nodeCount = 0;
        do
        {
            nodeCount++;
            currentNode = currentNode->nextNode;
        } while (currentNode != head);

        printf("The number of nodes present in the list are: %d", nodeCount);
    }
}

int main()
{
    int continueFlag = 1;
    while (continueFlag == 1)
    {
        printf("\n\n##############################################\n1.Create a Node\n\n2.Display the list\n--\n3.Insert the element at beginning\n4.Insert the element at the end\n5.Insert the element at specific position\n---\n6.Delete the element from the beginning\n7.Delete the element from the end\n8.Delete the element from specific position\n\n9.Count the total number of nodes\n10.Search an element in the linked list\n11.Exit\n=====================***======================\n");

        printf("\nEnter choice\n-->");
        int userChoice;
        scanf("%d", &userChoice);
        printf("\n\n------------------------------\n");
        switch (userChoice)
        {
        case 1:
            createCircularLinkedList();
            break;

        case 2:
            displayCircularLinkedList();
            break;

        case 3:
            insertAtBeginning();
            displayCircularLinkedList();
            break;

        case 4:
            insertAtEnd();
            displayCircularLinkedList();
            break;

        case 5:
            insertAtPosition();
            displayCircularLinkedList();
            break;

        case 6:
            deleteAtBeginning();
            displayCircularLinkedList();
            break;

        case 7:
            deleteAtEnd();
            displayCircularLinkedList();
            break;

        case 8:
            deleteAtPosition();
            displayCircularLinkedList();
            break;

        case 9:
            countNodes();
            break;

        case 10:
            searchElement();
            break;

        case 11:
            continueFlag = 0;
            break;

        default:
            printf("Invalid input");
        }
    }
    return 0;
}
