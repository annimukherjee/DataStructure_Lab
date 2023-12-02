// 7.2. Write a menu driven program to implementation of dequeue operations using linked list. The
// operation are such as :-

// 1. Insert at rear end
// 2. Insert at front end
// 3. Delete at front end
// 4. Delete at rear end
// 5. Display
// 6. Quit

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct deque
{
    int data;
    struct deque *next;
};
struct DQ
{
    struct deque *front;
    struct deque *rear;
};

typedef struct DQ DEQUE;

void initialize(DEQUE q);
bool isEmpty(DEQUE q);
void insert_front(DEQUE *q, int item);
void insert_rear(DEQUE *q, int item);
void delete_front(DEQUE *q);
void delete_rear(DEQUE *q);
void display(DEQUE *q);

int main()
{
    int c = 1;
    int ch = 0;
    DEQUE q;
    int item;
    initialize(q);
    while (c == 1)
    {
        printf("1.Insert at rear end\n2.Insert at front end\n3.Delete at front end\n4.Delete at rear end\n5.Display\n6.Exit\nEnter choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted:\n");
            scanf("%d", &item);
            insert_rear(&q, item);
            break;
        case 2:
            printf("Enter the number to be inserted:\n");
            scanf("%d", &item);
            insert_front(&q, item);
            break;
        case 3:
            delete_front(&q);
            break;
        case 4:
            delete_rear(&q);
            break;
        case 5:
            display(&q);
            break;
        case 6:
            exit(-1);
            break;
        default:
            printf("Wrong choice. Please enter a valid menu option.\n");
            break;
        }
    }
    return 0;
}

void initialize(DEQUE q)
{
    q.front = NULL;
    q.rear = NULL;
}

bool isEmpty(DEQUE q)
{
    if (q.front == NULL)
        return true;
    else
        return false;
}

void insert_front(DEQUE *q, int item)
{
    struct deque *ptr;
    ptr = (struct deque *)malloc(sizeof(struct deque));
    ptr->data = item;
    ptr->next = NULL;
    if ((q->front) == NULL)
    {
        q->rear = ptr;
    }
    else
    {
        ptr->next = (q->front);
    }
    q->front = ptr;
}

void insert_rear(DEQUE *q, int item)
{
    struct deque *ptr;
    ptr = (struct deque *)malloc(sizeof(struct deque));
    ptr->data = item;
    ptr->next = NULL;
    if (q->rear == NULL)
    {
        q->front = ptr;
    }
    else
    {
        (q->rear)->next = ptr;
    }
    q->rear = ptr;
}

void delete_front(DEQUE *q)
{
    int x;
    struct deque *temp;
    temp = (q->front);
    x = temp->data;
    q->front = temp->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    printf("\nThe number deleted from the queue is %d. \n", x);
}

void delete_rear(DEQUE *q)
{
    int x;
    struct deque *temp, *temp1;
    temp = (q->front);
    temp1 = NULL;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    x = temp->data;
    if (temp1 != NULL)
        temp1->next = temp->next;
    q->rear = temp1;
    if (q->rear == NULL)
        q->front = NULL;
    free(temp);
    printf("\nThe number deleted from the queue is %d.\n", x);
}

void display(DEQUE *q)
{
    struct deque *temp;
    temp = (q->front);
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}