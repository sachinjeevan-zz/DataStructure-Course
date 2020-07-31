#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void Rdisplay(struct Node *temp) // T(n) = T(n-1) + 1
{
    if( temp != NULL) // 1 unit
    {
        printf("%d ",temp->data); // 1 unit
        Rdisplay(temp->next); // T(n-1) unit
    }
}
void concatenateLL(struct Node* first, struct Node* second) // T(n) = 2n
{
    while(first->next != NULL) // n unit
    {
        first = first ->next; // n - 1 unit
    }
    first -> next = second; // 1 unit
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
    return First;

}
int main()
{
    struct Node* first = create();
    struct Node* second = create();
    concatenateLL(first, second);
    Rdisplay(first);
}