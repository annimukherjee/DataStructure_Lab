// 2205533_L8_P2_PrioQueueUsingLL

#include <stdio.h>
#include <stdlib.h>

struct pnode {
    int value;
    int priority;
    struct pnode *next;
};

typedef struct pnode PQueue;

PQueue *enqueue(PQueue *start);
PQueue *dequeue(PQueue *start);
void printQueue(PQueue *start);


PQueue *start = NULL;

int main() {
    int choice;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = enqueue(start);
                break;
            case 2:
                start = dequeue(start);
                break;
            case 3:
                printQueue(start);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    
    return 0;
}

void printQueue(PQueue *start) {
    PQueue *current = start;
    if (start == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Priority Queue contains:\n");
        while (current != NULL) {
            printf("%d [priority=%d] ", current->value, current->priority);
            current = current->next;
        }
    }
}


PQueue *enqueue(PQueue *start) {
    int val, pri;
    PQueue *newNode, *p;
    newNode = (PQueue *)malloc(sizeof(PQueue));
    
    printf("Enter value and its priority to be added to the queue:\n");
    scanf("%d %d", &val, &pri);
    
    newNode->value = val;
    newNode->priority = pri;
    
    if (start == NULL || pri < start->priority) {
        newNode->next = start;
        start = newNode;
    } else {
        p = start;
        while (p->next != NULL && p->next->priority <= pri) {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    return start;
}

PQueue *dequeue(PQueue *start) {
    PQueue *temp;
    if (start == NULL) {
        printf("\nQueue is empty.\n");
        return NULL;
    } else {
        temp = start;
        printf("\nDequeued item is: %d", temp->value);
        start = start->next;
        free(temp);
    }
    return start;
}
