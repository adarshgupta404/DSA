#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
struct node{
    int data;
    struct node*next;
}*start;

void create(int n){
    struct node *p;
    int i=0,item;
    p=(struct node*)malloc(sizeof(struct node));
    start=p;
    printf("Enter the %d element: ",i);
    scanf("%d",&item);
       p->data=item;
       p->next=NULL;
    //    start=p;
    i++;
    for ( i = 1; i < n; i++){
    p->next=(struct node*)malloc(sizeof(struct node));
    p=p->next;
        printf("Enter the %d element: ",i);
        scanf("%d",&item);
    p->data=item;
    p->next=NULL;
    }
}

void display(void){
    struct node*p=start;
    if (p==NULL)
        printf("No elements present\n");
    else {
    printf("[%d] ",start->data);
    p=start->next;
    while(p!=NULL){
        printf("--> ");
        printf("[%d] ",p->data);
        p=p->next;
    }
    }
    printf("\n");
}

void insert_head(int item){
struct node*p;
p=(struct node*)malloc(sizeof(struct node));
p->data=item;
p->next=start;
start=p;
}

int insert_end(int item){
    struct node*p=start,*q;
    q=(struct node*)malloc(sizeof(struct node));
    q->data=item;
    q->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    // printf("%s",p->next);
}
p->next=q;
}

void delete(int item){
    struct node*p=start,*q;
    int b=0,c=0;
    while(p!=NULL){
        if (p->data==item){
        c++;
        break;
        }
        q=p;
        p=p->next;
        b++;
    }
if (c==1 && p==start)
{
    printf("%d deleted at %d position\n",item,b);
    start=p->next;
free (p);
}
else  if(c==1){
    printf("%d deleted at %d position\n",item,b);
    q->next=p->next;
    free(p);
}
else if(c==0)
printf("Element not found\n");
}

void search(int item){
    struct node*p=start;
    int b=0,c=0;
    while(p!=NULL){
        if (p->data==item){
        c++;
        break;
        }
        p=p->next;
        b++;
    }
if (c==1 && p==start)
    printf("%d found at 0 (starting) position\n",item);
else  if(c==1)
    printf("%d found at %d position\n",item,b);
else if(c==0)
printf("Element not found\n");
}

void insert_pos(int loc,int item){
    struct node *p=start;
    int i=1;
    while(p->next!=NULL){
        i++;
        p=p->next;
    }
    // printf("%d\n",i);
    if (loc>i){
       printf("Invalid location\n");
       return;
    }
    if(loc==0)
        insert_head(item);
    
    else if(loc==i)
        insert_end(item);
    
    else {
        struct node *q,*temp;
        p=start;
        i=0;
        q=(struct node*)malloc(sizeof(struct node));
        q->data=item;
        while(i<loc){
            i++;
            temp=p;
            p=p->next;
    }
    temp->next=q;
    q->next=p;
    }
}

void insert_after(int pre,int item){
    struct node*p=start;
        int i=1;
    while(p!=NULL){
        if (p->data==pre)
        insert_pos(i,item);
        else 
            i++;
            p=p->next;
}
}

int count(void){
    int i=1;
    struct node *p=start;
    while(p->next!=NULL){
        i++;
        p=p->next;
    }
    return i;
}
void reverse(void){
    int i=1,j=0;
    struct node *p=start,*q=NULL;
    while(p->next!=NULL){
        p=p->next;
        i++;
    }
    if (i==1)
        return;
    if(i==2||i==3){
        int temp;
        temp=start->data;
        start->data=p->data;
        p->data=temp;
        printf("%d\n",i);
    }
if (i>3){
    int sta=1,end=i-2;
    int temp;
    temp=start->data;
    start->data=p->data;
    p->data=temp;
    while(sta<=end){
    int j=1,k=1;
        p=start,q=start;
        while(j<=sta){
            p=p->next;
            j++;
        }
        while(k<=end){
            q=q->next;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        sta++,end--;
    }
}
}
void sort(void)
{
    struct node *current = start, *index = NULL;
    int temp;
    if (start == NULL)
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

int main(){
printf("\nEnter the number of node to be created: ");
int n,a;
scanf("%d",&n);
create(n);
while(true){
        int item,loc;
printf("\nLINKED LIST MENU\n");
printf("1> DISPLAY\n2> INSERT AT HEAD \n3> INSERT AT END  \n4> INSERT AT POSITION\n5> INSERT AFTER A NODE\n6> DELETE\n7> SEARCH\n8> COUNT\n9> REVERSE\n10> SORT\n11.EXIT\n");
printf("Enter your choice: ");
scanf("%d",&a);
    switch (a){
    case 1:
        display();
        break;
    case 2:
    printf("Enter the element: ");
    scanf("%d",&item);
        insert_head(item);
        break;
    case 3:
    printf("Enter the element: ");
    scanf("%d",&item);
        insert_end(item);
        break;
    case 4:
    printf("Enter the position: ");
    scanf("%d",&loc);
    printf("Enter the item: ");
    scanf("%d",&item);
        insert_pos(loc,item);
        break;
    case 5:
    printf("Enter the already present item: ");
     scanf("%d",&loc);
    printf("Enter the item you want to insert after that: ");
    scanf("%d",&item);
        insert_after(loc,item);
        break;
    case 6:
    printf("Enter the element to delete: ");
    scanf("%d",&item);
        delete(item);
        break;
    case 7:
    printf("Enter the element to search: ");
    scanf("%d",&item);
        search(item);
        break;
    case 8:
    count();
    printf("Number of nodes = %d\n",count());
        break;
    case 9:
    reverse();
    break;
    case 10:
    sort();
    printf("After sorting: ");
    display();
    break;
    case 11:
    printf("Exitting...\n");
    exit(0);
    default:
    printf("Wrong input\tTRY AGAIN\n");
        break;
    }
}
return 0;
}
