#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
	int z;
public:
	Point();
	Point(int i, int j, int k);
	~Point();
	int getx();
	int gety();
	int getz();
};

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;

	cout<<"Constructing a point..."<<endl;
}

Point::Point(int i, int j, int k)
{
	x = i;
	y = j;
	z = k;

	cout<<"Constructing a point..."<<endl;
}

Point::~Point()
{
	cout<<"Destructing a point..."<<endl;
}

int Point::getx()
{
	return x;
}

int Point::gety()
{
	return y;
}

int Point::getz()
{
	return z;
}

int main(int argc, char *argv[])
{
	Point *MyPoint = new Point(3, 6, 9);
	cout<<*MyPoint.getx()<<endl<<*MyPoint.gety()<<endl<<*MyPoint.getz()<<endl;
	delete MyPoint;
	return 0;
}
