#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int a;
    struct node *next;
}list;

void menu(void);
void display(list *head);
list *createlist(list *head);
list *merge(list *head1, list *head2);


main()
{
    int wish;
    list *head1,*head2;
    head1=NULL;
    head2=NULL;

    printf("Create list 1\n");
    do
    {
      head1=createlist(head1);
      printf("Wish to continue?[0/1]:");
      scanf("%d",&wish);
    }while(wish==1);
    display(head1);

   // wish=0;
    printf("Create list 2\n");
    do
    {
      head2=createlist(head2);
      printf("Wish to continue?[0/1]:");
      scanf("%d",&wish);
    }while(wish==1);

    display(head2);
    printf("\n-----------------------------------------\n");


   printf("Merged list:\n");
   head1=merge(head1,head2);
   display(head1);
}


list* createlist(list *head)
{
    list *p,*newnode;

    newnode=(list*)malloc(sizeof(list));
    newnode->next=NULL;
    printf("Enter data:");
    scanf("%d",&newnode->a);


    if(newnode==NULL)
    {
        printf("Overflow...\n");
    }
     if(head==NULL)
    {
        head=newnode;
    }
    else
    {

        p=head;

       //make it circular
    while(p->next!=NULL)
    {
        p=p->next;
    }

        p->next=newnode;
    }

  return head;
}


list * merge(list *head1,list *head2)
{
    list *p1=head1;
    while(p1->next!=NULL)
    {
        p1=p1->next;
    }


    p1->next=head2;

    return head1;
}
void display(list *head)
{
    list *p=head;
    if(head==NULL)
        printf("List doesnt exist anymore\n");
    else
    {
        while(p!=NULL)
    {
        printf("%d\n",p->a);
        p=p->next;
    }

    }
}
