#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void addToEmpty(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    *head = temp;
}

void insert_beg(struct node **head, int d)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = d;
    temp->next = NULL;
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
}

void insert_end(struct node **head, int d)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next = NULL;
    struct node *temp = *head;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insert_after_position(struct node **head)
{
    printf("Enter poistion after you want to insert: ");
    int p;
    scanf("%d", &p);
    printf("Enter element you want to insert after the position: ");
    int d;
    scanf("%d", &d);

    struct node *temp2 = NULL;
    struct node *temp = *head;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next = NULL;
    newNode->prev = NULL;

    while (p != 1)
    {
        temp = temp->next;
        p--;
    }

    temp2 = temp->next;
    temp->next = newNode;
    temp2->prev = newNode;
    newNode->next = temp2;
    newNode->prev = temp;
}

void insert_before_position(struct node **head)
{
    printf("Enter poistion before you want to insert: ");
    int p;
    scanf("%d", &p);

    struct node *temp2 = NULL;
    struct node *temp = *head;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;

    while (p > 2)
    {
        temp = temp->next;
        p--;
    }
    if (p == 1)
    {
        printf("Enter the element: ");
        int d;
        scanf("%d", &d);
        insert_beg(head, d);
    }
    else
    {
        printf("Enter element you want to insert before the position: ", p);
        int d;
        scanf("%d", &d);
        newNode->data = d;
        temp2 = temp->next;
        temp->next = newNode;
        temp2->prev = newNode;
        newNode->next = temp2;
        newNode->prev = temp;
    }
}

void display(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("[%d]--->", temp->data);
        temp = temp->next;
    }
}

void getLength(struct node **head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = *head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    printf("Number of Nodes present in Doubly Linked list is %d.\n", len);
}

void createList(struct node **head)
{
    printf("Enter the number of nodes you want to insert: ");
    int n;
    scanf("%d", &n);
    if (n == 0)
        return;
    printf("Enter the data at 1: ");
    int d;
    scanf("%d", &d);
    addToEmpty(head, d);
    for (int i = 1; i < n; i++)
    {
        printf("Enter the data at %d: ", i + 1);
        int d;
        scanf("%d", &d);
        insert_end(head, d);
    }
}

void delete_firstNode(struct node **head)
{
    *head = (*head)->next;
    free((*head)->prev);
    printf("\nAfter deleting the first node: \n");
    display(head);
}

void delete_lastNode(struct node **head)
{
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    free(temp);
    printf("\nAfter deleting the last node: \n");
    display(head);
}

void delete_intermediate(struct node** head)
{
    int p;
    printf("Enter the position of the Node you want to delete: ");
    scanf("%d", &p);
    struct node* temp = *head, *temp2 = NULL;
    if(p==1)
        delete_firstNode(head);
    while (p>1) 
    {
        temp = temp->next;
        p--;
    }
    if(temp->next==NULL)
        delete_lastNode(head);
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next; 
        temp->prev = temp2;
        free(temp);
        temp = NULL;
    }   
}

void reverse(struct node** head)
{
    struct node* ptr1 = *head;
    struct node* ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2!=NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    *head = ptr1;
}

void sort(struct node** head)
{
    struct node *current = *head, *index = NULL;
    int temp;
    if (*head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // index points to the node next to current
            index = current->next;

            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

int main()
{
    struct node *head = NULL;
    createList(&head);
    printf("\nDOUBLE LINKED LIST MENU:\n1.DISPLAY\n2.INSERT AT ENDING\n3.INSERT AT BEGINNING\n4.INSERT AFTER POSITON\n5.INSERT BEFORE POSITON\n6.NO OF NODES\n7.DELETE FIRST NODE\n8.DELETE LAST NODE\n9.DELETE INTERMEDIATE\n10.REVERSE\n11.SORT \nAny key-EXIT\n");
        
    int d1, d2, d3;
    while (1)
    {
        int a;
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            display(&head);
            break;
        case 2:
            printf("Enter the element at ending: ");
            scanf("%d", &d1);
            insert_end(&head, d1);
            break;
        case 3:
            printf("Enter the element at beginning: ");
            scanf("%d", &d2);
            insert_beg(&head, d2);
            break;
        case 4:
            insert_after_position(&head);
            break;
        case 5:
            insert_before_position(&head);
            break;
        case 6:
            getLength(&head);
            break;
        case 7:
            delete_firstNode(&head);
            break;
        case 8:
            delete_lastNode(&head);
            break;
        case 9:
            delete_intermediate(&head);
            break;
        case 10:
            reverse(&head);
            display(&head);
            break;
        case 11:
            sort(&head);
            display(&head);
            break;
        default:
            goto end;
        }
        printf("\n");
    }
end:
    return 0;
}
