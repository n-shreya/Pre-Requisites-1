#include<stdio.h>
typedef struct phonepay
{
    int tid;
    char s[10];
    char r[10];
    float amnt;
    char t[5];
}UPI;
void read(UPI x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i].tid);
        fflush(stdin);
        gets(x[i].s);
        fflush(stdin);
        gets(x[i].r);
        scanf("%f",&x[i].amnt);
        fflush(stdin);
        gets(x[i].t);
    }
}
void display(UPI x[],int n)
{
    int i;
    printf(" The transaction details are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%s\t%f\t%s\n",x[i].tid,x[i].s,x[i].r,x[i].amnt,x[i].t);
    }
}
void search_Tid(UPI x[],int Tid,int n)
{
   int i;
   for(i=0;i<n;i++)
   {
       if(Tid==x[i].tid)
       {
          printf("%d\t%s\t%s\t%f\t%s\n",x[i].tid,x[i].s,x[i].r,x[i].amnt,x[i].t);
          break;
       }
   }
}
void search(UPI x[],char user[],int n)
{
    int i,flag=1;
    for(i=0;i<n;i++)
    {
        flag=strcmp(user,x[i].s);
        if(flag==0)
        {
           printf("%d\t%s\t%s\t%f\t%s\n",x[i].tid,x[i].s,x[i].r,x[i].amnt,x[i].t);
        }
    }

}
int main()
{
    UPI x[100];
    int n,Tid,c;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    char user[10];
    read(x,n);
    display(x,n);
     printf("Enter the transaction id to search:\n");
    scanf("%d",&Tid);
    search_Tid(x,Tid,n);
    printf("Enter the user name to search:\n");
    fflush(stdin);
    gets(user);
    search(x,user,n);
}
