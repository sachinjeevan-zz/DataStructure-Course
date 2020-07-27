#include<stdio.h>
#include<stdlib.h>
// Node Structure
struct Node
{
    int data;
    struct Node* next;
};
// Iterative Approach of counting Nodes
void countNodes(struct Node* temp) // T(n) = 3 + 3N  => O(N) // Linear Time Taking  
{
    int count = 0; // 1 unit
    while( temp != NULL ) // N + 1 unit 
    {
        count++; // N unit
        temp = temp -> next ; // N unit
    }
    printf("Length of the Linked List is %d",count); // 1 unit
}
// Recursive Approach of counting Nodes
void RcountNodes(struct Node *temp, int count) // T(n) = T(n-1) + 1
{
    if(temp==NULL) // 1 unit
    {
        printf("Length of the linked list is %d",count);// 1 unit
    }
    else
    {
        RcountNodes(temp->next, count+1); // T(n-1)
    }
    
}
void create()
{
    struct Node *First,*last;
    First = (struct Node*)malloc(sizeof(struct Node)); 
    int x; 
    scanf("%d",&x);
    First -> data = x; 
    last = First;
    last -> next = NULL;
    scanf("%d",&x);
    while(x != -1)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
        temp->data = x;
        last -> next = temp;
        last = temp;
        last -> next = NULL;
        scanf("%d",&x);
    }
    RcountNodes(First, 0);
   
}
int main()
{
    create();
}