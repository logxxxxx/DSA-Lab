#include <iostream>
using namespace std;	
long long int table[100] = { -1 }; // memo array with all element initialized to -1

long long int fibo(int n) {
	if (n <= 1) return n;
	else if (table[n] != -1) return table[n]; 
	else {
		table[n] = fibo(n - 1) + fibo(n - 2); 
		return table[n];
	}
}	

int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	long long int result = fibo(n);
	cout << "Fibonacci number for " << n << " is: " << result << endl;
	return 0;
}





