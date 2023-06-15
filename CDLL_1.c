#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a;
    char n[20];
    struct node *next, *prev;
}LIST;

void menu()
{
    printf("Menu:\n");
    printf("1.Insert at front\n");
    printf("2.Insert at end\n");
    printf("3.Insert at position\n");
    printf("4.Delete at front\n");
    printf("5.Delete at end\n");
    printf("6.Delete at position\n");
    printf("7.Reverse the list\n");
    printf("8.Display\n");
    printf("9.Exit\n");
}
LIST  *createlist(LIST * head, int a)
{
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow...\n");
        exit(0);
    }

    newnode->a=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
            newnode->prev=head;
        }
        else
        {
           LIST *p=head;
           p=head->prev;
           newnode->next=head;
           newnode->prev=p;
           p->next=newnode;
           head->prev=newnode;
        }

    return head;
}

void reverse(LIST *head)
{
    LIST *p;
    p=head->prev;
    do
    {
        printf("%d\n",p->a);
        p=p->prev;
    }while(p!=head->prev);
}

//count no. of nodes in list
int getcount(LIST *head)
{
    int count=0;
    LIST *p=head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

LIST *insert_front(LIST *head, int a)
{
    LIST *p;
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow...\n");
        exit(0);
    }
    newnode->a=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
        newnode->prev=head;
    }
    else
    {
        p=head->prev;
        newnode->next=head;
        p->next=newnode;
        newnode->prev=p;
        head=newnode;
    }
    return head;

}

/*LIST *insert_end(LIST *head,int a)
{
    LIST *p=head;
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow...\n");
        exit(0);
    }
    //if list contains only one node
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }
    newnode->a=a;
    p->next=newnode;
    newnode->next=NULL;
    return head;
}

/*LIST *insert_pos(LIST *head, int pos, int a)
{
    LIST *p,*newnode;
    int i,count;

    //get count of nodes
    count=getcount(head);

    //if invalid position
    if(pos>=count)
    {
        printf("Invalid position...\n");
        return head;
    }

    //allocate memory
    newnode=(LIST *)malloc(sizeof(LIST));
    if(newnode==NULL)
    {
        printf("Overflow....\n");
        exit(0);
    }
    newnode->a=a;
    newnode->next=NULL;

    //insert at front
    if(pos==0)
    {

        newnode->next=head;
        head=newnode;
        return head;
    }

    //insert at end
    else if(pos==count-1)
    {
            //traverse to end
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
            return head;
    }

    //insert in between
    else
    {
        p=head;
        for(i=0;i<pos-1; i++)
        {

            p=p->next;
        }
        newnode->next=p->next;
        p->next=newnode;
        return head;
    }
}

LIST *delete_front(LIST *head)
{
    LIST *p=head;
    if(p==NULL)
    {
        printf("Empty list...\n");
        free(p);
    }
    head=head->next;
    p->next=NULL;
    free(p);
    return head;
}

LIST *delete_end(LIST *head)
{
    LIST *p=head;
    LIST *pp=head;
    if(p==NULL)
    {
        printf("Empty list...\n");
        free(p);
    }
    else
    {
        while(p->next!=NULL)
        {
            pp=p;
            p=p->next;
        }
        pp->next=NULL;
        free(p);
        return head;
    }
}

LIST *delete_pos(LIST *head, int pos)
{
    int i;
    LIST *p,*pp;

    p=head;
    pp=head;

    //get node count
    int count=getcount(head);

    //if position given is more than nodes available
    if(pos>=count)
    {
        printf("Invalid position...\n");
        return head;
    }

    //if position entered is 0
    if(pos==0)
    {
        head=head->next;
        free(p);
        return head;
    }

    //other positions
    for(i=0; i<pos;i++)
    {
        pp=p;
        p=p->next;
    }
    pp->next=p->next;
    p->next=NULL;
    free(p);
    return head;
}*/

void display(LIST *head)
{
    LIST *p=head;
    printf("The list is:\n");
    do
    {
        printf("%d\n",p->a);
        p=p->next;
    }while(p!=head);
}

int main()
{
    LIST *head;
    int a,wish,ch,pos;
    head=NULL;

    do
    {
        printf("Enter the data:");
        scanf("%d",&a);
        head=createlist(head,a);
        printf("Wish to continue[1/0]:");
        scanf("%d",&wish);
    }while(wish==1);

    do
    {
        menu();
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1:printf("Enter the data:");
                scanf("%d",&a);
                head=insert_front(head,a);
                break;

         /*case 2:printf("Enter the data:");
                scanf("%d",&a);
                head=insert_end(head,a);
                break;

         case 3:printf("Enter the data:");
                scanf("%d",&a);
                printf("Enter the pos:");
                scanf("%d",&pos);
                head=insert_pos(head,pos,a);
                break;

         case 4:head=delete_front(head);
                break;


         case 5:head=delete_end(head);
                break;

         case 6:printf("Enter the pos:");
                scanf("%d",&pos);
                head=delete_pos(head,pos);
                break;*/

        case 7:reverse(head);
               break;

         case 8:display(head);
                break;

         /*default:exit(0);*/
        }
    }while(1);
}

