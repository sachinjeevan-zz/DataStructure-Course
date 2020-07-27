#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
// Iterative Approach
void sumOfLL(struct Node* temp) // T(N) = 3N + 3 = O(N)
{
    int sum = 0; // 1 unit
    while( temp!=NULL ) // N+1 unit
    {
        sum += temp->data; // N unit
        temp = temp->next; // N unit
    }
    printf("Sum of all the nodes in Linked List is %d",sum); // 1 unit
}
// Recursive Approach
int RsumOfLL(struct Node* temp)// T(N) = T(N-1) + 1     T(0) = 1
{
    if(temp==NULL) // 1 unit
    {
        return 0; // 1 unit
    }
    else
    {
        return temp->data + RsumOfLL(temp->next);// 1 + T(N-1)
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
    int ans = RsumOfLL(First);
    printf("Sum of all the nodes in Linked List is %d",ans);
   
}
int main()
{
    create();
}