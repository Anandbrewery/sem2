#include <stdio.h>
#include <stdlib.h>
struct node{
    int dat;
    struct node *next;
};
struct node* create_ll(struct node*head)
{
    int n,i;
    struct node *ptr;
    struct node *newnode;
    printf("enter number of nodes:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        newnode=(struct node*)(malloc(sizeof(struct node)));
        if(i==0)
        {
            head=newnode;
        }
        else
        {
            ptr->next=newnode;
        }
        printf("newnode->dat: ");
        scanf("%d",&newnode->dat);
        newnode->next=NULL;
        ptr=newnode;
    }

    return head;
}
struct node* display_ll(struct node*start) 
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->dat);
        ptr=ptr->next;
    }

    return start;
}
struct node * swap (struct node* head)
{
    printf("hi");
    struct node **link;
    struct node *prev;
    struct node *current;
    
    *link =head;
    prev=*link;
    while(prev->next!=NULL)
    {
        printf("hi");
        struct node *temp1;
        struct node *temp2;
        temp2=current->next;
        temp1=prev->next;
        *link=temp1;
        current->next=prev;
        prev->next=temp2;
        prev=current->next;
        if(current->next!=NULL)
        {
            current=current->next->next;
        }
       
    }
    return *link;
}
void main()
{
    struct node *head=NULL;
    head=create_ll(head);
    display_ll(head);
    head=swap(head);
    display_ll(head);
}
