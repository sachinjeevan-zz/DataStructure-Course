#include<stdio.h>
#include<stdlib.h>
// Node Structure
struct Node
{
    int data;
    struct Node* next;
};
// display the linked list ( iterative )
void display(struct Node *temp)// T(n) = 3N + 1 = O(N)
{
    while(temp != NULL)// N+1 unit
    {
        printf("%d ",temp->data); // N unit 
        temp = temp->next; // N unit
    }
}
// display the linked list ( recursive )
void Rdisplay(struct Node *temp) // T(n) = T(n-1) + 1
{
    if( temp != NULL) // 1 unit
    {
        printf("%d ",temp->data); // 1 unit
        Rdisplay(temp->next); // T(n-1) unit
    }
}

// Creating the linked list
void create() // T(n) = 10 + 7N = O(N) // Linear Time Taking
{
    struct Node *First,*last; // 2 unit
    First = (struct Node*)malloc(sizeof(struct Node)); // 2 unit 
    int x; // 1 unit 
    scanf("%d",&x); // 1 unit
    First -> data = x; // 1 unit 
    last = First; // 1 unit
    last -> next = NULL; // 1 unit
    scanf("%d",&x); // 1 unit 
    while(x != -1) // N unit
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // N unit 
        temp->data = x; // N unit
        last -> next = temp; // N unit 
        last = temp; // N unit
        last -> next = NULL; // N unit
        scanf("%d",&x); // N unit 
    }
    Rdisplay(First);
}
int main()
{
    create();
}