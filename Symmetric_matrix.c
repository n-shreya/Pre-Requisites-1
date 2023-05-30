#include<stdio.h>

void read(int a[10][10], int p, int q)
{
    int i,j;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void check(int a[10][10], int p, int q)
{
    int flag=0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            if(a[i][j]==a[j][i])
            {
                flag=1;

            }
            else
            {
                flag=0;
            }
        }
    }
    if(flag==1)
    {
        printf("The Matrix is symmetric\n");
    }
    else
    {
        printf("The Matrix is not symmetric\n");
    }
}

int main()
{
    int a[10][10],i,j,p,q;
    printf("Enter the rows and columns of the matrix:\n");
    scanf("%d%d",&p,&q);
    read(a,p,q);
    printf("The Matrix formed is:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    check(a,p,q);
}
