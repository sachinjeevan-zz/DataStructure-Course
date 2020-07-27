#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
// iterative approach
struct Node* Search(struct Node* temp, int key) // T(n) = 3N + 3  => O ( N )
{
    while( temp!= NULL) // N + 1 unit      //      1 unit
    {
        if(temp -> data == key) // N unit      //  1 unit
        {
            return temp; // 1 unit            // 1 unit
        }
        temp = temp->next; // N unit
    }
    return NULL; // 1 unit
}
// Recursive Approach
struct Node* RSearch(struct Node* temp, int key) // T(n) = T(n-1) + 1    T(0) = 1
{
    if(temp == NULL) // 1 unit
        return NULL; // 1 unit 
    if(temp->data == key) // 1 unit
        return temp; // 1 unit 
    RSearch(temp->next, key); // T(n-1)
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
    struct Node* result = RSearch(First, 56);
    if(result==NULL)
        printf("Element is not found");
    else
        printf("The element %d is found",result->data);
   
}
int main()
{
    create();
}