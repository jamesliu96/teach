#include <iostream>

using namespace std;

void func(int *n);

int main(int argc, char *argv[])
{
	int a;
	a = 9;


	int *b = &a;


	func(b);


	cout<<a<<endl;

	return 0;
}

void func(int *n)
{
	*n = *n + 1;
}
