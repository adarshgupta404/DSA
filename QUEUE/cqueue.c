#include <stdio.h>
#define MAX 5
#define true 1
#define false 0
int cqueue[MAX], rear = -1, front = -1;

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (rear == MAX - 1 && front == 0 || front == rear + 1)
        return 1;
    else
        return 0;
}

void peep()
{
    int i;
    if (isEmpty())
        printf("Empty Queue\n");
    else
    {
        // printf("\n Front -> %d ", front);
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", cqueue[i]);
        }
        printf("%d ", cqueue[i]);
        // printf("\n Rear -> %d \n", rear);
    }
}

void insert(void)
{
    if (isFull())
    {
        printf("CQUEUE OVERFLOW\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
        rear = rear + 1;
    int item;
    printf("Enter item to insert: ");
    scanf("%d", &item);
    cqueue[rear] = item;
    return;
}

void delete (void)
{
    if (front == -1)
        printf("CQUEUE UNDERFLOW\n");
    else
        printf("Deleted item is %d\n", cqueue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
        front++;
    return;
}

int main()
{
    printf("CIRCULAR QUEUE MENU\t1.INSERT\t2.DELETE\t3.PEEP\tAny key-EXIT\n");
    while (true)
    {
        int a;
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            insert();
            break;

        case 2:
            delete ();
            break;

        case 3:
            peep();
            break;

        default:
            goto end;
        }
        printf("\n");
    }
end:
    return 0;
}