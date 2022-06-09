#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* prev; 
    int val;
    struct node* next; 
};
struct node* create(struct node *head)
{
    struct node*ptr;
    struct node*newnode;
    
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
   
    printf("newnode->val: ");
    scanf("%d",&newnode->val);
    printf("k");
    newnode->next=NULL;
    head=newnode;
    printf("k");
    printf("%d",newnode->val);
    return head;
} 
struct node* display(struct node* head){
    struct node*ptr;
    ptr=head;
    printf("k");
    while(ptr->next!=head||ptr->next!=NULL)
    {
        printf("%d",ptr->val);
        ptr=ptr->next;
    }
    printf("%d",ptr->val);
    return head;
}
int main()
{
    struct node* head=NULL;
    head=create(head);
    head=display(head);
    //begin(head);
    return 0;
}
