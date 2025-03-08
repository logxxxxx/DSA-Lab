#include <iostream>
#include <time.h>
using namespace std;


void merge(int arr[], int l, int m, int r)
 {
	int i = l; 
	int j = m; 
	int k = l; 
	int B[100000];

	while (i<m && j<=r) 
	{
		if (arr[i] < arr[j]) 
		{
			B[k++] = arr[i++]; 
		} 
		else 
		{
			B[k++] = arr[j++]; 
		}

	}

	for(i,k; i<m; i++,k++) 
	{
		B[k] = arr[i]; 
	}
	for(j,k; j<=r; j++ , k++) 
	{
		B[k] = arr[j]; 
	}
	for(k=l;k<=r;k++)	
	{
		arr[k] = B[k]; 
	} 
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
	{
        int m = (l+r)/2; 

		mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr,l,m+1, r);
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

	//Display(arr, n);

    start = clock();
	mergeSort(arr, 0, n-1);
    end = clock();

	//Display(arr, n);

    cout << "Time taken by Merge Sort: " 
         << static_cast<double>(end - start) / CLOCKS_PER_SEC 
         << " seconds" << endl;
    return 0;


}


	


    







 