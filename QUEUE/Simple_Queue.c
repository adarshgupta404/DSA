#include <stdio.h>
#define MAX 4
int queue[MAX], rear = -1, front = -1;

void enqueue(void)
{
    if (rear == MAX - 1)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    rear++;
    int item;
    printf("Enter item to insert: ");
    scanf("%d", &item);
    queue[rear] = item;
    if (front == -1)
    {
        front = 0;
    }
    return;
}

void dequeue(void)
{
    if (front == -1)
        printf("QUEUE UNDERFLOW\n");
    else
        printf("Deleted item is %d\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        queue[front] = -1;
        front++;
    }
        
    return;
}

void peep(void)
{
    if (front == -1)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    while (1)
    {
        int a;
        printf("SIMPLE QUEUE MENU:\t1.INSERT   2.DELETE   3.PEEP   Any key-EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
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
