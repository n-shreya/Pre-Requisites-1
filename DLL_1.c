#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a;
    struct node *next, *prev;
}LIST;

int getcount(LIST *head)
{
    int count=0;
    LIST *p=head;
    do
    {
        count++;
        p=p->next;
    }while(p!=NULL);
    return count;
}

int main()
{
    LIST *head,*newnode,*p,*pp;
    head=NULL;
    int wish;

    //creating a list
    do
    {
        newnode=(LIST*)malloc(sizeof(LIST));
        newnode->next=NULL;
        newnode->prev=NULL;
        printf("Enter the data:");
        scanf("%d",&newnode->a);
        if(head==NULL)
        {
            head=newnode;
            p=head;
        }
        else
        {
            p->next=newnode;
            newnode->prev=p;
            p=p->next;
        }
        printf("Wish to continue[1/0]:");
        scanf("%d",&wish);

    }while(wish==1);

    //printing the list in forward direction
    printf("List is printed in Forward Order:\n");
    p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->a);
        p=p->next;
    }
    printf("\n");

    //traverse the list to the end
    printf("List is printed in Reverse Order:\n");
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }

    //printing the list in reverse direction
    do
    {
        printf("%d\t",p->a);
        p=p->prev;
    }while(p!=NULL);
    printf("\n");
    //printf("End of list ....\n");

    //insert a node at the beginning
    /*newnode=(LIST*)malloc(sizeof(LIST));
    printf("Enter the data:");
    scanf("%d",&newnode->a);
    newnode->next=NULL;
    newnode->prev=NULL;
    p=head;
    if(head==NULL)
    {
        head=newnode;
        p=head;
    }
    else
    {
        newnode->next=head;
        p->prev=newnode;
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
    newnode->next=NULL;
    newnode->prev=NULL;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
    newnode->prev=p;
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");*/

    //insert a node at any position
    newnode=(LIST*)malloc(sizeof(LIST));
    int pos,count;
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the data:");
    scanf("%d",&newnode->a);
    newnode->next=NULL;
    newnode->prev=NULL;
    p=head;

    //pos=0{first node}
    count=getcount(head);
    if(pos==0)
    {
        if(count==0)
        {
            head=newnode;
        }

         else
        {
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }

    //pos in between
    else
    {
        p=head;
        for(int i=0;i<pos;i++)
        {
            p=p->next;
        }
        if(p->next!=NULL)
        {
            p->next->prev=newnode;
        }
        newnode->next=p->next;
        p->next=newnode;
        newnode->prev=p;
    }
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");

    //delete a node at beginning
    /*p=head;
    head=p->next;
    p->next->prev=head;
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
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->prev->next=NULL;
    free(p);
    p=head;
    printf("Last node deleted and the list is printed\n");
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    //printf("End of list ....\n");*/

    //delete a node at any position
    printf("Enter the position:");
    scanf("%d",&pos);
    count=getcount(head);

    p=head;
    if(pos==0)
    {
        if(count==0)
        {
            printf("Empty list...\n");
        }

        //list contains only 1 node
        else if(head->next==NULL)
        {
            free(p);
            head=NULL;
        }

        //list contains many nodes
        else
        {
          p=head;
          head=head->next;
          head->prev=NULL;
          free(p);
        }
    }
    else
    {
        p=head;
        for(int i=0;i<pos;i++)
        {
            pp=p;
            p=p->next;
        }

        //if node to delete is not last node
        if(p->next!=NULL)
        {
            p->prev->next=pp;
        }
        pp->next=p->next;
        free(p);
    }
    p=head;
    printf("Required node deleted and the list is printed\n");
    while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }
    printf("End of list ....\n");
}
