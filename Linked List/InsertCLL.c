#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void displayCLL(struct Node* first) // T(n) = 4n + 1 = O(n)
{
    struct Node* temp = first; // n unit
    do
    {
        printf("%d ",temp->data); // n unit
        temp = temp -> next; // n unit
    }while(temp!=first); // n + 1 unit
}
int RcountNodes(struct Node *temp, int count) // T(n) = T(n-1) + 1
{
    struct Node* t = temp;
    static int flag=0;
    if(flag!=0 && t==temp) // 1 unit
    {
        return count;// 1 unit
    }
    else
    {
        flag = 1;
        return RcountNodes(t->next, count+1); // T(n-1)
    }
    
}
struct Node* insertCLL(struct Node* first, int pos, int x,int len) // T(n)
{ // T(n) = 2n + 7
    if(pos<=len) // 1 unit
    {
        if(pos==0) // 1 unit
        {
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // 1 unit
            temp->data = x; // 1 unit
            if(first==NULL) // 1 unit
            {
                first = temp; // 1 unit
                first->next = first; // 1 unit
            }
            else
            {
                temp->next = first; // 1 unit
                struct Node* t = first; // 1 unit
                while( t->next != first) // n unit
                {
                    t = t->next; // n-1 unit
                }
                t->next = temp; // 1 unit
            }
            
        }
        else
        // T(n) = 3n + 5
        {
            struct Node* temp = first; // 1 unit
            for(int i=0;i<pos-1;i++)// 1 unit  // n unit // n unit
            {
                temp = temp->next; // n-1 unit
            }
            struct Node* new = (struct Node*)malloc(sizeof(struct Node)); // 1 unit
            new->data = x; // 1 unit
            new->next = temp->next; // 1 unit
            temp->next = new; // 1 unit
        }
        

        
        
    }
    return first;
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
    last->next = First;
    return First;

}
int main()
{
    struct Node* first = create();
    int len = 5;
    first = insertCLL(first,0,12,len);
    displayCLL(first);

}