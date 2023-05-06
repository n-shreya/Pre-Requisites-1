#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
        {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        {
        arr[k] = L[i];
        i++;
        k++;
        }

    while (j < n2)
        {
        arr[k] = R[j];
        j++;
        k++;
        }
}

void merge_sort(int arr[], int l, int r)
{   int m;
    if (l < r)
        {
        m = l+(r-l)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
        }
}

int main()
{
    int n,a,b,num;
    int arr[100000];
    FILE *fp;

    printf("Enter the number of elements to generate: ");
    scanf("%d", &n);

    printf("Enter the range (a b) to generate numbers in: ");
    scanf("%d %d", &a, &b);

    fp = fopen("Input.txt", "w");
    srand(time(0));

    for (int i = 0; i < n; i++)
        {
        num = rand() % (b - a + 1) + a;
        fprintf(fp, "%d ", num);
        }

    fclose(fp);

    printf("Generated %d numbers in the range (%d, %d) and wrote to file Input.txt\n",n,a,b);

    FILE *fp_in, *fp_out;

    fp_in = fopen("Input.txt", "r");
    fp_out = fopen("Output.txt", "w");

    printf("Sorting has started\n");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp_in, "%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        fprintf(fp_out, "%d ", arr[i]);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("Sorted %d numbers from Input.txt and wrote to Output.txt using Merge sort\n",n);

    return 0;
}
