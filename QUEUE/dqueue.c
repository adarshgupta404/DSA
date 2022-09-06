#include <stdio.h>    
#define true 1  
#define size 5  
int deque[size];    
int f = -1, r = -1;  

void insert_front(int x)    
{    
    if((f==0 && r==size-1) || (f==r+1))    
    {    
        printf("Overflow");    
    }    
    else if((f==-1) && (r==-1))    
    {    
        f=r=0;    
        deque[f]=x;    
    }    
    else if(f==0)    
    {    
        f=size-1;    
        deque[f]=x;    
    }    
    else    
    {    
        f=f-1;    
        deque[f]=x;    
    }    
}    
       
void insert_rear(int x)    
{    
    if((f==0 && r==size-1) || (f==r+1))    
    {    
        printf("Overflow\n");    
    }    
    else if((f==-1) && (r==-1))    
    {    
        r=0;    
        deque[r]=x;    
    }    
    else if(r==size-1)    
    {    
        r=0;    
        deque[r]=x;    
    }    
    else    
    {    
        r++;    
        deque[r]=x;    
    }    
    
}    
    
// display function prints all the value of deque.    
void display()    
{    
    int i=f;    
    printf("\nElements in a deque are: ");    
        
    while(i!=r)    
    {    
        printf("%d ",deque[i]);    
        i=(i+1)%size;    
    }    
     printf("%d\n",deque[r]);    
}    
    
// getfront function retrieves the first value of the deque.    
void getfront()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty\n");    
    }    
    else    
    {    
        printf("\nThe value of the element at front is: %d\n", deque[f]);    
    }    
        
}    
    
// getrear function retrieves the last value of the deque.    
void getrear()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty\n");    
    }    
    else    
    {    
        printf("\nThe value of the element at rear is %d\n", deque[r]);    
    }    
        
}    
    
// delete_front() function deletes the element from the front    
void delete_front()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty\n");    
    }    
    else if(f==r)    
    {    
        printf("\nThe deleted element is %d\n", deque[f]);    
        f=-1;    
        r=-1;    
            
    }    
     else if(f==(size-1))    
     {    
         printf("\nThe deleted element is %d\n", deque[f]);    
         f=0;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d\n", deque[f]);    
          f=f+1;    
     }    
}    

void delete_rear()    
{    
    if((f==-1) && (r==-1))    
    {    
        printf("Deque is empty\n");    
    }    
    else if(f==r)    
    {    
        printf("\nThe deleted element is %d\n", deque[r]);    
        f=-1;    
        r=-1;    
            
    }    
     else if(r==0)    
     {    
         printf("\nThe deleted element is %d\n", deque[r]);    
         r=size-1;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d\n", deque[r]);    
          r=r-1;    
     }    
}    
    
int main()    
{ 
    printf("DOUBLE ENDED QUEUE MENU: \n1.INSERT front\n2.DELETE front\n3.PEEP\n5.INSERT rear\n6.DELETE rear\nAny key-EXIT\n");
        
    while(true){
    int a;
        printf("Enter your choice: ");
        scanf("%d", &a);
        int it;
        switch (a)
        {
        case 1:
            printf("\nEnter item from front: ");
            scanf("%d",&it);
            insert_front(it);
            break;
        case 5:
            printf("\nEnter item from rear: ");
            scanf("%d",&it);
            insert_rear(it);
            break;
        case 2:
            delete_front();
            break;
        case 6:
            delete_rear();
            break;
        case 3:
            display();
            break;
        default:
        goto end;
            break;
        }
    }
    end:
    return 0;
}     