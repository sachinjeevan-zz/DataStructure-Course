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
struct Node* mergeLL(struct Node* first, struct Node* second) // T(n,m) =   6(n+m) + 10  =   O ( n + m)
{
    struct Node *third,*last; // 2 unit
    if(first -> data < second -> data) //1 unit
    {
        third = last = first; // 1 unit
        first = first -> next; // 1 unit
        last ->next = NULL; // 1 unit
    }
    else
    {
        third = last = second; // 1 unit
        second = second -> next; // 1 unit
        last->next = NULL; // 1 unit
    }
    while( first!=NULL && second!=NULL ) // n + m + 1
    {
        if(first->data < second->data) // n + m unit
        {
            last->next = first; // n + m unit
            last = first; // n + m
            first = first->next; // n + m
            last->next = NULL; // n + m
        }
        else
        {
            last ->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if(first!=NULL) // 1 unit
    {
        last->next = first; // 1 unit
    }
    if( second!= NULL)
    {
        last->next = second;
    }
    return third; // 1 unit
    
    
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

     struct Node* third = mergeLL(first,second);
     Rdisplay(third);


}