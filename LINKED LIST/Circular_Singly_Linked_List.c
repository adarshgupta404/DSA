#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* next;
};

void addEmpty(struct node** last, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    *last = newNode;
    (*last)->next = *last;
}

int getLength(struct node** last)
{
    struct node* temp = (*last)->next;
    int cnt = 1;
    while (temp!=*last)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void insert_end(struct node** last, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*last)->next;
    (*last)->next = newNode;
    *last = newNode;
}

void createList(struct node** last)
{
    printf("Enter the number of nodes you want to insert: ");
    int n;
    scanf("%d", &n);
    if (n == 0)
        return;
    printf("Enter the data at 1: ");
    int d;
    scanf("%d", &d);
    addEmpty(last,d);
    for (int i = 1; i < n; i++)
    {
        printf("Enter the data at %d: ", i + 1);
        int d;
        scanf("%d", &d);
        insert_end(last,d);
    }
}

void insert_beg(struct node** last, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*last)->next;
    (*last)->next = newNode;
}

void insert_bet(struct node** last, int data)
{
    struct node* p = (*last)->next, *newNode = (struct node*)malloc(sizeof(struct node));
    int pos;
    printf("\nEnter the position you want: ");
    scanf("%d", &pos);
    while (pos>1)
    {
        p = p->next;
        pos--;
    }
    newNode->next = p->next;
    p->next = newNode;
    newNode->data = data;
    if(p == *last) 
        *last = (*last)->next; 
}

void delete_firstNode(struct node** last)
{
    struct node* temp = (*last)->next;
    (*last)->next = temp->next;
    free(temp);
    temp = NULL;
}

void delete_lastNode(struct node** last)
{
    struct node* temp = (*last)->next;
    while (temp->next != *last)
    {
        temp = temp->next;
    }
    temp->next = (*last)->next;
    free(*last);
    *last = temp;
}

void delete_intermediate(struct node** last)
{
    int pos;
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        delete_firstNode(last);
        return;
    }    
    
    int l = getLength(last);
    if(pos==l)
    {
        delete_lastNode(last);
        return;
    }
    
    struct node* temp = (*last)->next;
    while (pos>2)  
    {
        temp = temp->next;
        pos--;
    }
    struct node* temp2 = temp->next;
    temp->next = temp2->next;
    if(temp2 == *last)
        *last = temp;
    free(temp2);
    temp2 = NULL;
}

void display(struct node** last)
{
    if (last == NULL) {
        printf("The list is empty");
        return;
    }
    struct node* temp = (*last)->next;
    do{
        printf("[%d]--->",temp->data);
        temp = temp->next;
    }while(temp != (*last)->next);
    printf("\n");
}

void search(struct node** last)
{
    int d;
    printf("Enter the data: ");
    scanf("%d", &d);
    struct node* temp = (*last)->next;
    while (temp != *last)
    {
        if(temp->data == d)
        {
            printf("%d is present.",d);
            return;
        }
            temp = temp->next;
    }   
    printf("Not Present.");
}

void reverse(struct node** last)
{
    struct node* currN, *prevN, *nextN;
    currN = (*last)->next;
    nextN = currN->next;
    while (currN!=*last)
    {
        prevN = currN;
        currN = nextN;
        nextN = currN->next;
        currN->next = prevN;
    }
    nextN->next = *last;
    *last = nextN;
}

int main()
{
    struct node* last = NULL;
    createList(&last);
    int d1, d2, d3, l;
    printf("\nDOUBLE LINKED LIST MENU:\n1.DISPLAY\n2.INSERT AT ENDING\n3.INSERT AT BEGINNING\n4.INSERT AFTER POSITON\n5.DELETE FIRST NODE\n6.DELETE LAST NODE\n7.DELETE INTERMEDIATE NODE\n8.GET LENGTH\n9.SEARCH\n10.REVERSE \nAny key-EXIT\n");
    while (1)
    {
        int a;
        printf("\nEnter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            display(&last);
            break;
        case 2:
            printf("Enter the element at ending: ");
            scanf("%d", &d1);
            insert_end(&last, d1);
            display(&last);
            break;
        case 3:
            printf("Enter the element at beginning: ");
            scanf("%d", &d2);
            insert_beg(&last, d2);
            display(&last);
            break;
        case 4:
            printf("Enter the element at position: ");
            scanf("%d", &d3);
            insert_bet(&last,d3);
            display(&last);
            break;
        case 5:
            delete_firstNode(&last);
            display(&last);
            break;
        case 6:
            delete_lastNode(&last);
            display(&last);
            break;
        case 7:
            delete_intermediate(&last);
            display(&last);
            break;
        case 8:
            l = getLength(&last);
            printf("Length of the linked list is %d", l);
            break;
        case 9:
            search(&last);
            break;
        case 10:
            reverse(&last);
            display(&last);
            break;
        default:
            goto end;
        }
    }
end:
return 0;
}
