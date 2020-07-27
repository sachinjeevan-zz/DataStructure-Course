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
void removeDuplicates(struct Node* p, struct Node* q) // T(n) = 7n + 1
{
    while(q!=NULL) // n + 1 unit
    {
        if(p->data == q->data) // n unit
        {
            p->next = q->next; // n unit
            free(q); // n unit
            q = p->next; // n unit
        }
        else
        {
            p = p->next; // n unit
            q = q->next; // n unit
        }
    }
    
}
void RremoveDuplicates(struct Node* p,struct Node* q) // T(n) = T(n-1) + 1   T(0) = 1
{
    if(q!=NULL) // 1 unit
    {
        if(p->data == q->data) // 1 unit
        {
            p->next = q->next; // 1 unit
            RremoveDuplicates(p,p->next);
        }
        else
        {
            RremoveDuplicates(p->next,q->next); // T(n-1)
        }
        
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
    RremoveDuplicates(First,First->next);
    Rdisplay(First);
}
int main()
{
    create();
}