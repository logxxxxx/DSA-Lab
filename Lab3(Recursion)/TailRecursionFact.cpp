#include <iostream>
using namespace std;	

long long int fact(int n,long int acc)
{
	if(n==0||n==1)
		return acc;
	else
		return fact(n-1,acc*n);
}
int main()
{
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	long long int result=fact(num,1);
	cout<<result<<endl;
	return 0;	

}