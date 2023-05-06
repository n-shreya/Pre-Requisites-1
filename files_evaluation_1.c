#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n,a,b,num;
    printf("Enter the number of random numbers to be generated: ");
    scanf("%d", &n);
    printf("Enter the lower and upper bounds (a, b) of the range: ");
    scanf("%d %d", &a, &b);


    FILE *fp;
    fp = fopen("Input.txt", "w");


    srand(time(0));
    for(int i=0; i<n; i++)
        {
        num = (rand() % (b-a+1)) + a;
        fprintf(fp, "%d\n", num);
        }


    fclose(fp);

    printf("Generated %d random numbers to Input.txt\n", n);

    return 0;
}
