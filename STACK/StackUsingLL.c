#include<stdio.h> 
#include<stdlib.h> 

#define bool int 

struct sNode 
{ 
   int data; 
   struct sNode *next; 
}; 

void push(struct sNode** top_ref, int new_data); 

int pop(struct sNode** top_ref); 

bool isEmpty(struct sNode* top); 

void print(struct sNode* top); 

int main() 
{ 
    struct sNode *s = NULL; 
    int choice = 0, input = 0; 
    printf("Stack operations using linked list\n"); 
    printf("==================================\n"); 
    while(1) 
    { 
        printf("Choose one of the following options:\n"); 
        printf("\n 1.Push \n 2.Pop \n 3.Print \n 4.Exit"); 
        printf("\n Enter your choice: "); 
        scanf("%d",&choice); 
        switch(choice) 
        { 
            case 1: 
            { 
                printf("Enter your input: "); 
                scanf("%d",&input); 
                push(&s, input); 
                break; 
            } 
            case 2: 
            { 
                int popped_element = pop(&s); 
                if(popped_element == -1) 
                    printf("Stack is empty\n"); 
                else
                    printf("Popped element: %d \n",popped_element); 
                break; 
            } 
            case 3: 
            { 
                if(isEmpty(s)) 
                    printf("Stack is empty\n"); 
                else
                    print(s); 
                break; 
            } 
            case 4: 
            { 
                exit(0); 
                break; 
            } 
            default: 
            { 
                printf("Invalid option \n"); 
            } 
        } 
    } 
    return 0; 
} 

/* Function to push data to stack */
void push(struct sNode** top_ref, int new_data) 
{ 
    struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode)); 
    if(new_node == NULL) 
    { 
        printf("Stack overflow \n"); 
        getchar(); 
        exit(0); 
    } 
    new_node->data = new_data; 
    new_node->next = *top_ref; 
    *top_ref = new_node; 
} 

/* Function to pop data from stack */
int pop(struct sNode** top_ref) 
{ 
    int res; 
    struct sNode *top; 
    if(*top_ref == NULL) 
    { 
        return -1; 
    } 
    else
    { 
        top = *top_ref; 
        res = top->data; 
        *top_ref = top->next; 
        free(top); 
        return res; 
    } 
} 

/* Function to check if stack is empty */
bool isEmpty(struct sNode* top) 
{ 
    return (top == NULL)? 1 : 0; 
} 

/* Function to print stack elements */
void print(struct sNode* top) 
{ 
    while(top != NULL) 
    { 
        printf("%d ", top->data); 
        top = top->next; 
    } 
    printf("\n"); 
}