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
struct Node* reverseLinks(struct Node* first) // T(n) = 4n + 9
{
    struct Node *p,*q,*r; // 3 unit
    p = first; // 1 unit
    q = r = NULL; // 2 unit
    while(p!=NULL) // n + 1 unit
    {
        r = q; // n unit
        q = p; // n unit
        p = p->next; // n unit
        q->next = r; // n unit
    }
    first = q; // 1 unit
    return first; // 1 unit

}
void create() 
{
    struct Node *First,*last; 
    First = (struct Node*)malloc(sizeof(struct Node)); 
    int x; 
    scanf("%d",&x); 
    First -> data = x;  
    int len = 1;
    last = First; 
    last -> next = NULL; 
    scanf("%d",&x); 
    while(x != -1) 
    {
        len++;
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  
        temp->data = x; 
        last -> next = temp; 
        last = temp; 
        last -> next = NULL; 
        scanf("%d",&x); 
    }

    First = reverseLinks(First);
    Rdisplay(First);


}
int main()
{
   create();
}