#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
int isLoop(struct Node* temp) // T(n) = 9n + 6 = O(n)
{
    struct Node *p,*q; // 2 unit
    p = q = temp; // 2 unit
    do
    {
        p = p->next; // n unit
        q = q->next; // n unit
        q = q!=NULL ? q->next : NULL; // 2n unit
    } while (p!=NULL && q!=NULL && p!=q); // 5n unit

    return p==q? 1 : 0; // 2 unit
    
}
int RisLoop(struct Node* temp, struct Node* p, struct Node* q, int count) // T(n) = T(n-1) + 1    T(0) = 1
{
    if( ( count==0 ) || (p!=NULL && q!=NULL && p!=q)) // 7 unit
    {
        return q->next!=NULL ? RisLoop(temp,p->next,q->next->next,count+1) : RisLoop(temp,p->next,NULL,count+1);// 1 + T(n-1)
    }
    else
    {
        return p==q ? 1 : 0; // 2 unit
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
    return First;

}
int main()
{
    struct Node* first = create();
    int flag = RisLoop(first,first,first,0);
    flag==1 ? printf("Linked List is having Loop") : printf("Linked List is Linear");
}