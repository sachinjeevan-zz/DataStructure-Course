#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node
{
    int data;
    struct Node* next;
};
int isSorted(struct Node* temp) // T(n) = 5n + 8 = O(n)
{
    int x = INT_MIN; // 1 unit
    while(temp!=NULL && temp->data >= x) // (3n + 3) // 2 unit 
    {
        x = temp->data; // n + 1 unit // 1 unit
        temp = temp->next; // n + 1 unit // 1unit 
    }
    if(temp==NULL) // 1 unit
    {
        return 1; // 1 unit
    }
    else
    {
        return 0;
    }

}
int RisSorted(struct Node* temp,int x) // T(n) = T(n-1) + 1      T(0) = 1
{
    if(temp!=NULL && temp->data >=x) // 3 unit
    {
        RisSorted(temp->next,temp->data); //T(n-1)
    }
    else
    {
        if(temp==NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
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
    int flag = RisSorted(First, INT_MIN);
    if(flag == 1)
    {
        printf("Linked List is Sorted");
    }
    else
    {
        printf("Linked List is not sorted");
    }
    
    
}
int main()
{
  create();
}