#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* insertSortedNode(struct Node* p, struct Node* q, int key)// T(n)
{ // T(n) = 3N + 8
    while( p->data < key ) // N unit 
    {
        q = p; // N unit
        p = p->next; // N unit
    }

    struct Node* t = (struct Node*)malloc(sizeof(struct Node)); // 1 unit
    t->data = key; // 1 unit
    if(q!=NULL) // 1 unit
    {
        t->next = q->next; // 1 unit
        q->next = t; // 1 unit
    }
    else
    {
        t->next = p; // 1 unit
        return t; //  1 unit
    }
    return NULL; // 1 unit
    
}

struct Node* RinsertSortedNode(struct Node* p, struct Node* q, int key)
{// T(n)  =   T(n-1) + 1           T(0) = 1

    if( p->data < key) // 1 unit 
    {
        RinsertSortedNode(p->next, p, key); // T(n-1)
    }
    else
    {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        if(q!=NULL)
        {
            t->next = q->next;
            q->next = t;
        }
        else
        {
            t->next = p;
            return t;
        }
    
    }
    return NULL;
    
}
void Rdisplay(struct Node *temp) // T(n) = T(n-1) + 1
{
    if( temp != NULL) // 1 unit
    {
        printf("%d ",temp->data); // 1 unit
        Rdisplay(temp->next); // T(n-1) unit
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

    struct Node* y = RinsertSortedNode(First,NULL,45);
    if(y!=NULL)
    {
        First = y;
    }
    Rdisplay(First);
    
}
int main()
{
    create();
}