#include <iostream>
#include <time.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
	int i,j,least,pos,temp;
	for(i=0; i<n;i++)
	{
		least = arr[i];
		pos = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<least)
			{
				least = arr[j];
				pos = j;
			}
		}
		if(i != pos)
		{
			temp = arr[i];
			arr[i] = arr[pos];
			arr[pos] = temp;
		}
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

	 SelectionSort(arr,n);

    start = clock();
	SelectionSort(arr,n);
    end = clock();

    cout << "Time taken by Selection Sort: " 
         << static_cast<double>(end - start) / CLOCKS_PER_SEC 
         << " seconds" << endl;

    SelectionSort(arr,n); 
    return 0;

}


