#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a;
    struct node *next;
}LIST;

int main()
{
    LIST *head,*newnode,*p,*pp;
    head=NULL;
    int wish;

    //creating a list
    do
    {
        newnode=(LIST*)malloc(sizeof(LIST));
        printf("Enter the data:");
        scanf("%d",&newnode->a);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            p=newnode;
        }
        else
        {
            p->next=newnode;
            p=newnode;
        }
        printf("Wish to continue[1/0]:");
        scanf("%d",&wish);

    }while(wish==1);
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");

    //search an element in a list
    p=head;
    int key;
    printf("Enter the value you want to search:");
    scanf("%d",&key);
    while(p!=NULL)
    {
        if(p->a==key)
        {
            printf("Found!\n");
            break;
        }
        else
        {
            p=p->next;
        }
    }
    if(p==NULL)
        printf("Not found!\n");

    //insert a node at the beginning
    newnode=(LIST*)malloc(sizeof(LIST));
    printf("Enter the data:");
    scanf("%d",&newnode->a);
    if(head!=NULL)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        head=newnode;
    }
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");

    //insert a node at the end
    newnode=(LIST*)malloc(sizeof(LIST));
    printf("Enter the data:");
    scanf("%d",&newnode->a);
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");

    //insert a node at any position
    int pos;
    newnode=(LIST*)malloc(sizeof(LIST));
    printf("Enter the data:");
    scanf("%d",&newnode->a);
    p=head;
    printf("Enter the position:");
    scanf("%d",&pos);
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");

    //delete a node at the beginning
    p=head;
    head=head->next;
    p->next=NULL;
    free(p);
    p=head;
    printf("Beginning node deleted and the list is printed\n");
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");

    //delete a node at the end
    p=head;
    pp=head;
    while(p->next!=NULL)
    {
        pp=p;
        p=p->next;
    }
    pp->next=NULL;
    free(p);
    p=head;
    printf("Last node deleted and the list is printed\n");
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");

    //delete at specific element
    int a;
    printf("Enter the data you want to delete:");
    scanf("%d",a);
    p=head;
    pp=head;
    if(head==NULL)
    {
        free(p);
    }
    else
    {
        while(p->a!=a)
    {
        pp=p;
        p=p->next;
    }
    pp->next=p->next;
    p->next=NULL;
    free(p);
    }
    p=head;
    printf("List after deleting %d :\n",a);
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //deletion based on position//
    printf("Enter the position:\n");
    scanf("%d",&pos);
    p=head;
    pp=head;
    if(head==NULL)
    {
        free(p);
    }
    else
    {
        for(int i=0;i<pos;i++)
    {
        pp=p;
        p=p->next;
    }
    }
    pp->next=p->next;
    p->next=NULL;
    free(p);
    p=head;
    printf("List after deleting node at position:\n",a);
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    printf("End of list ....\n");

    //count the no of nodes in a list
    newnode=head;
    int cnt=0;
    if(newnode==NULL)
    {
        printf("No nodes are formed\n");

    }
    while(newnode!=NULL)
    {
        newnode=newnode->next;
        cnt++;

    }
    printf("Number of nodes:%d\n",cnt);

    return 0;
}
