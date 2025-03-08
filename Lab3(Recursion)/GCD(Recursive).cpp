#include <iostream>
using namespace std;	
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
int main()
{
	int a, b;
	int tempValue = 0;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	if(a>b)
	{
		tempValue = (a,b);
	} 
	else
	{
		tempValue = (b,a);
	}
	cout << "GCD of " << a << " and " << b << " is " << tempValue << endl;
	return 0;
}