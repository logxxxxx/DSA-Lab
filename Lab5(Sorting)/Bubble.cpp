#include <iostream>
#include <time.h>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array
void display(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

     //display(arr, n);

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    cout << "Time taken by Bubble Sort: " 
         << static_cast<double>(end - start) / CLOCKS_PER_SEC 
         << " seconds" << endl;

     //display(arr, n);
    return 0;
}
