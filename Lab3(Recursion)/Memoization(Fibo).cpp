
#include <iostream>
#include <vector>
using namespace std;


int fibonacci(int n, vector<int> &DynamicArr) {
    if (n <= 1) return n;

    if (DynamicArr[n] = -1)
	{
		DynamicArr[n] = fibonacci(n - 1, DynamicArr) + fibonacci(n - 2, DynamicArr);
		return DynamicArr[n];
	} 
	else
	{
		DynamicArr[n];
	} 
}

int main() {
    int n;
    cout << "Enter the term (n) to find in the Fibonacci sequence: ";
    cin >> n;


    vector<int> DynamicArr(n + 1, -1);

    int result = fibonacci(n, DynamicArr);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}
