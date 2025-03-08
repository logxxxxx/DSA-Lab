#include "iostream"
using namespace std;	

void TOH(int n, char source, char destination, char temporary)
{
	if (n == 1)
	{
		cout << "Move disk 1 from " << source << " to " << destination << endl;
		return;
	}
	TOH(n - 1, source, temporary, destination);
	cout << "Move disk " << n << " from " << source << " to " << destination << endl;
	TOH(n - 1, temporary, destination, source);
}
int main()
{
	int n;
	cout << "Enter the number of disks: ";
	cin >> n;
	TOH(n, 'A', 'C', 'B');
	return 0;
}


