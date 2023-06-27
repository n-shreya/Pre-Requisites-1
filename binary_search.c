// C program to implement iterative Binary Search

#include <stdio.h>



int binarySearch(int arr[30], int l, int r, int x)

{

	while (l <= r) {

		int m = l + (r - l) / 2;

		if (arr[m] == x)

			return m;

		if (arr[m] < x)

			l = m + 1;

		else

			r = m - 1;

	}

	return -1;

}



int main()

{

	int arr[30],n;

	printf("Enter the number of elements in an array:\n");

	scanf("%d",&n);

	printf("Enter the elements of an array:\n");

	for(int i=0;i<n;i++)

    {

      scanf("%d",&arr[i]);

    }

	int a = sizeof(arr) / sizeof(arr[0]);

	int x;

	printf("Enter the element to be searched in an array:\n");

	scanf("%d",&x);

	int result = binarySearch(arr, 0, a - 1, x);

	(result == -1) ? printf("Element is not present in array",result)

		          : printf("Element is present at index %d",result);

	return 0;

}
