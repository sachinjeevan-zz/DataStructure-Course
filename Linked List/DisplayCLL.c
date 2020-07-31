#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void displayCLL(struct Node* first) // T(n) = 4n + 1 = O(n)
{
    struct Node* temp = first; // n unit
    do
    {
        printf("%d ",temp->data); // n unit
        temp = temp -> next; // n unit
    }while(temp!=first); // n + 1 unit
}
void RdisplayCLL(struct Node* head, struct Node* temp) // T(n) = T(n-1) + 1   if n==0  T(0) = 1
{
    static int flag = 0; // 1 unit
    if( flag == 0 || temp!=head ) // 3 unit
    {
        flag = 1; // 1 unit
        printf("%d ",temp->data); // 1 unit
        RdisplayCLL(head,temp->next); // T(n-1)
    }
}
struct Node* create() 
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
    last->next = First;
    return First;

}
int main()
{
    struct Node* first = create();
    RdisplayCLL(first,first);
}