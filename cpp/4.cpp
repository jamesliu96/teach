#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	long a[n];
	a[0] = 0;
	a[1] = 1;
	for(int i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
