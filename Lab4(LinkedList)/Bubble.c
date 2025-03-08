#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
    int i, j,temp;;
	for (i = 0; i < n-1; i++) 
	{
		for (j = 0; j < n-i-1; j++) 
		{
			if(arr[j] > arr[j+1]) 
			{ 
				temp = arr[j]; 
				arr[j] = arr[j+1]; 
				arr[j+1] = temp; 
			} 
		}

	}
}

// fuction to display the array

void Display(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
    printf("\n");
}

int main()
{
	int n, i;
	clock_t start,end;
	srand(time(NULL));
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[100000];
	for ( i = 0; i < n; i++)
	{
		arr[i] = rand();;

	}
	//Display(arr, n); 
	start=clock();
	bubbleSort(arr,n);
	end=clock();
	printf("Time taken by Bubble Sort: %f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
	//Display(arr, n);
	return 0;
}









