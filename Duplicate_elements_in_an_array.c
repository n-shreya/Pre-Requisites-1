#include <stdio.h>

void countduplicates(int a[],int size)
{
    int count;
    for (int i=0;i<size;i++)
    {
        count=1;
        for (int j=i+1;j<size;j++)
        {
            if (a[i]==a[j])
            {
                count++;
                a[j]=-1;
            }
        }
        if (count>1&&a[i]!=-1)
        {
            printf("%d appears %d times\n",a[i],count);
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int a[size];
    printf("Enter the elements of the array:\n");
    for (int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Duplicate elements and their counts:\n");
    countduplicates(a,size);
    return 0;
}

