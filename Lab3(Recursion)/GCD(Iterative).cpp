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
		while (b != 0)
		{
			int r = a % b;
			a = b;	
			b = r;
		}
		return a;
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