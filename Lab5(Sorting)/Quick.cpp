// sort the array using the quicksort algorithm

#include <iostream>
#include <time.h>
using namespace std;

int partition(int arr[], int l, int r)
{
	int L = l, R = r;
	int pivot = arr[l];
	int temp;

	while (L<R)
	{
		while (arr[L] <= pivot)
		{
			L++;
		}
		
		while (arr[R] > pivot)
		{
			R--;
		}
		
		if (L < R)
		{
			temp = arr[L];
			arr[L] = arr[R];
			arr[R] = temp;
		}
	
	}
	arr[l] = arr[R];
	arr[R] = pivot;
	return R;

}

void quickSort(int arr[], int l, int r)
{
	int p;
	if (l > r)
	{
		p = partition(arr, l, r);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, r);
	}	
}

void Display(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

}

int main()
 {
	int n;
    clock_t start, end;

    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

	Display(arr, n);

    start = clock();
	quickSort(arr, 0, n-1); 
    end = clock();

	Display(arr, n);

    cout << "Time taken by Selection Sort: " 
         << static_cast<double>(end - start) / CLOCKS_PER_SEC 
         << " seconds" << endl;

	
    return 0;

}


