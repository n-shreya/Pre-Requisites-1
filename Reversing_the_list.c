#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a;
    char n[20];

    struct node *next;
}LIST;

int main()
{
    LIST *head,*newnode,*p,*pp;
    int wish;

    //initialize head to null
    head=NULL;

    //create a list
    do
    {
        newnode=(LIST*)malloc(sizeof(LIST));
        printf("Enter the data:");
        scanf("%d",&newnode->a);
        newnode->next=NULL;

        //check if list exits or not
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
    printf("Original list:\n");
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    printf("End of list ....\n");

    //reversing the list
    pp=NULL;
    while(head!=NULL)
    {
        p=head;
        head=head->next;
        p->next=pp;
        pp=p;
    }
    head=p;
    printf("Reversed list:\n");
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
}
