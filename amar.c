/*A Amar Rohith
  EC21B1106*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *current;
};
struct node* display_LL(struct node*);
struct node* insertbeginning_LL(struct node*,int item);
struct node* insertend_LL(struct node*,int item);
struct node* insertbefore_LL(struct node*start,int item_b,int item);
struct node* insertafter_LL(struct node*start,int item_b,int item);
struct node* deletebeginning_LL(struct node*start);
struct node* deleteend_LL(struct node*start);
struct node* deletespef_LL(struct node*start,int item);
int counter(struct node*start,int item);
struct node* addressfinder(struct node *start,int item);


struct node* display_LL(struct node*start) //functions to display the linked list
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->value);
        ptr=ptr->current;
    }
    return start;
}


struct node* insertend_LL(struct node*start,int item) //function ti insert in the end
{
    struct node *newnode;
    struct node *ptr;
    newnode=malloc(sizeof(struct node));
    if(start==NULL)
    {
        start=newnode;
        newnode->value=item;
        
    }
    else
    {
        newnode->value=item;
        ptr=start;
        while(ptr->current!=NULL)
        {
            ptr=ptr->current;
        }
        ptr->current=newnode;
        newnode->current=NULL;
    }
    return start;
}
struct node* insertbeginning_LL(struct node*start,int item) //function to insert in the start
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->current=start;
    newnode->value=item;
    start=newnode;
    return start;
}
struct node* insertbefore_LL(struct node*start,int item_b,int item) //function to insert before a given element
{
    struct node *newnode,*ptr,*preptr;
    ptr=start;
    preptr=NULL;
    newnode=malloc(sizeof(struct node));
    while(ptr->value!=item_b)
    {
        preptr=ptr;
        ptr=ptr->current;
    }
    
    if(preptr==NULL)
    {
        start=newnode;
        newnode->value=item;
        newnode->current=ptr;
       
    }
    else
    {
        newnode->value=item;
        newnode->current=ptr;
        preptr->current=newnode;
    }
    return start;
}
struct node* insertafter_LL(struct node*start,int item_b,int item) //function to insert after a given element
{
    struct node *newnode,*ptr,*postptr;
    postptr=start;
    newnode=malloc(sizeof(struct node));
    while(postptr->value!=item_b)
    {
        ptr=postptr;
        postptr=postptr->current;
    }
    ptr=postptr;
    postptr=postptr->current;
    newnode->value=item;
    newnode->current=postptr;
    ptr->current=newnode;
    return start;
}
struct node* deletebeginning_LL(struct node*start) //function to delete the starting element
{
    start=start->current;
    return start;
}
struct node* deleteend_LL(struct node*start) //function to delete the end element
{
    struct node *ptr,*preptr;
    while(ptr->current!=NULL)
    {
        preptr=ptr;
        ptr=ptr->current;
    }
    preptr->current=NULL;
    return start;
}
struct node* deletespef_LL(struct node*start,int item) //function to delete the a particular node
{
    struct node *ptr,*preptr,*postptr;
    while(ptr->value!=item)
    {
        preptr=ptr;
        ptr=ptr->current;
    }
    postptr=ptr->current;
    preptr->current=postptr;
    ptr->current=NULL;
    return start;
}
int counter(struct node*start,int item) //function to count number of occurence given the element
{
    int count=0;
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->value==item)
        {
            count=count+1;
        }
        ptr=ptr->current;
    }
    return count;
}
struct node* addressfinder(struct node *start,int item) //function to find the address of the element if it exists in the linked list
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->value==item)
        {
           return ptr;
        }
        ptr=ptr->current;
    }
    
}
void main()
{
    int count;    //To check the working of the code taking manual as well as user inputted inputs to test the working of the functions.
    struct node *Start=NULL,*Add;
    /*int num,place;
    printf("Enter an element to add in the end:");
    scanf("%d",&num);
    Start=insertend_LL(Start,num);
    printf("Enter an element to add in the beginning:");
    scanf("%d",&num);
    Start=insertbeginning_LL(Start,num);
    printf("Enter the item value before which the number should be added:");
    scanf("%d",&place);
    printf("Enter an element to add:");
    scanf("%d",&num);
    Start=insertbefore_LL(Start,place,num);
    printf("Enter the item value after which the number should be added:");
    scanf("%d",&place);
    printf("Enter an element to add:");
    scanf("%d",&num);
    Start=insertafter_LL(Start,place,num);*/
    Start=insertend_LL(Start,20);
    Start=insertend_LL(Start,40);
    Start=insertend_LL(Start,60);
    Start=insertbeginning_LL(Start,10);
    Start=insertbefore_LL(Start,10,15);
    Start=insertafter_LL(Start,40,45);
    Start=deletebeginning_LL(Start);
    Start=deleteend_LL(Start);
    Start=deletespef_LL(Start,40);
    Start=insertend_LL(Start,20);
    Start=display_LL(Start);
    count=counter(Start,20);
    Add=addressfinder(Start,45);
    printf("\ncount=%d,Address=%p",count,Add);
}
