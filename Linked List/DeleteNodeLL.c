#include<stdio.h>
#include<stdlib.h>
struct Node{
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
struct Node* deleteNode(struct Node* p, struct Node* q, int pos)// T(n) = 4N + 4
{
    if(pos==1) // 1 unit
    {
        struct Node* temp = p->next; // 1 unit
        free(p); // 1 unit
        return temp; // 1 unit
    }
    else{
        int i=1; // 1 unit
        while(i<pos) // N unit
        {
            q = p; // N unit
            p = p->next; // N unit
            i++; // N unit
        }
        q->next = p->next; // 1 unit
        free(p); // 1 unit
        return NULL; //1 unit
    }
}
struct Node* RdeleteNode(struct Node* p,struct Node* q, int i,int pos)// T(n) = T(n-1) + 1
{    //  T(0) = 1
    if(pos==1)// 1 unit
    {
        struct Node* temp = p->next; // 1unit
        free(p); // 1 unit
        return temp; // 1 unit
    }
    else if(i<pos) // 1 unit
    {
        RdeleteNode(p->next, p,i+1,pos); // T(n-1)
    }
    else
    {
        q->next = p->next; // 1 unit 
        free(p); // 1 unit

    }
    return NULL; // 1 unit
    
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
    struct Node* y = RdeleteNode(First,NULL,1,1);
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