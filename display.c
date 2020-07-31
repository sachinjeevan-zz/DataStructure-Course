#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void Rdisplay(struct Node* temp)
{
    if( temp!=NULL)
    {
        printf("%d ",temp->data);
        Rdisplay( temp->next );
    }

}
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