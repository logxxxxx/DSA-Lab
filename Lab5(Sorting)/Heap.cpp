// // sort the array using the heap sort algorithm

#include <iostream>
#include <time.h>
using namespace std;

void MaxHeapify(int arr[], int n, int i)
 {
    int l = 2*i+1, r= 2*i+2, largest=i, temp;

	if (l<n && arr[l]>arr[largest])
	{
		largest=l;
	}

	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		MaxHeapify(arr, n, largest);
	}
}

void BuildMaxHeap(int arr[], int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		MaxHeapify(arr,n,i);
	}
}

void HeapSort(int arr[], int n)
 {
    BuildMaxHeap(arr, n);
	int i,temp;
	for(i = n-1; i >0;i --)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		MaxHeapify(arr,i,0);
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
	HeapSort(arr, n);
    end = clock();

	Display(arr, n);

    cout << "Time taken by Merge Sort: " 
         << static_cast<double>(end - start) / CLOCKS_PER_SEC 
         << " seconds" << endl;
    return 0;


 }

//function to add fibbo series
int 




 

