#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node
{
    int data;
    struct Node *next;
};
// iterative approach 
int maxNode(struct Node* temp) // T(n) = 4N + 3  = O ( N )
{
    int max = INT_MIN; // 1 unit
    while(temp!=NULL) // N + 1 unit
    {
       if(temp->data > max) // N unit
       {
           max = temp -> data; // N unit
       }
       temp = temp->next; // N unit
    }
    return max; // 1 unit
}
// recursive approach
int RmaxNode(struct Node *temp, int max) // T(n) =  T(n-1) + 2        T(0) = 1
{
    if(temp!=NULL) // 1unit 
    { // 1 unit 
        temp->data > max ? RmaxNode(temp->next,temp->data) : RmaxNode(temp->next,max); // T(n-1)
    }
    else
    {
        return max;
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
   int maxElement = RmaxNode(First,INT_MIN);
   printf("The maximum element is %d",maxElement);
}
int main()
{
    create();
}