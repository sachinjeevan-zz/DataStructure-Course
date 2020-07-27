#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void Rdisplay(struct Node *temp) 
{
    if( temp != NULL) 
    {
        printf("%d ",temp->data);
        Rdisplay(temp->next); 
    }
}
// T(n) = 3N + 7 = O ( N )
struct Node* insertNode(struct Node* p, int data, int insert_point) 
{
    struct Node *first = p; // 1 unit
    for(int i=0;i<insert_point-1;i++) 
    {
        p = p->next; 
    }
    struct Node* t = (struct Node*)malloc(sizeof(struct Node)); // 1 unit
    t->data = data; // 1 unit
    if(insert_point == 0)
    {
        t->next = first; // 1 unit
        first = t; // 1 unit
    }
    else
    {
        t->next = p->next; 
        p->next = t; 
    }
    
    return first; // 1 unit
}
struct Node* RinsertNode(struct Node* First, struct Node* p, int curr_pos,int insert_point, int data)
{ // T(n)= T(n-1) + 1             T(0) = 1
    if(curr_pos < insert_point-1) //  1 unit
    {
        RinsertNode(First,p->next,curr_pos+1,insert_point,data); // T(n-1)
    }
    else
    {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node)); // 1 unit
        t->data = data; // 1 unit
        if(insert_point == 0) // 1 unit
        {
            t->next = First; // 1 unit
            First = t; // 1 unit
        }
        else 
        {
            t->next = p->next; // 1unit 
            p->next = t; // 1 unit
        }
    
    return First; // 1 unit
    }
    
}
void RcreateLinkedList(struct Node* First,int x,int i)//T(n) = T(n-1) + n    T(0) = 1
{
    if(i<5) // 1 unit
    {
        scanf("%d",&x); // 1 unit
        First = insertNode(First,x,i); // N unit
        RcreateLinkedList(First,x,i+1); // T(n-1)
    }
    else
    {
        Rdisplay(First);
    }
}
void createLinkedList() // T(n) = N^2 + 2N + 2   =  O ( N^2 )
{
    struct Node* First =NULL; // 1 unit
    int x; // 1 unit
    for(int i=0;i<5;i++) // N unit
    {
        scanf("%d",&x); // N unit
        First = insertNode(First,x,i); // N x N unit
    }
    Rdisplay(First); 

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
    Rdisplay(First);
    First = RinsertNode(First,First,0,0,100);
    First = RinsertNode(First,First,0,4,200);
    Rdisplay(First);
}
int main()
{
    RcreateLinkedList(NULL, -1, 0);
}