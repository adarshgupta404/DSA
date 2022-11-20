#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// This function should add a new node at the rear of the queue
void Enqueue()
{
    int x;
    scanf("%d", &x);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// This function should remove a node from front of the queue
void Dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

// Function to get front node value
int Front()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    return front->data;
}

// Function to get rear node value
int Rear()
{
    if (rear == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    return rear->data;
}

// Function to print the queue
void Print()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("[%d] ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int a;
        printf("\nSIMPLE QUEUE MENU:\t1.INSERT   2.DELETE   3.PRINT  Any key-EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            Enqueue();
            break;

        case 2:
            Dequeue();
            break;

        case 3:
            Print();
            break;

        default:
            goto end;
        }
    }
end:
    return 0;
}
