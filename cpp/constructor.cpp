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
    this->x = 0;
    this->y = 0;
    this->z = 0;

    cout<<"Constructing a point..."<<endl;
}

Point::Point(int i, int j, int k)
{
    this->x = i;
    this->y = j;
    this->z = k;

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
    Point MyPoint(3, 6, 9);
    cout<<MyPoint.getx()<<endl<<MyPoint.gety()<<endl<<MyPoint.getz()<<endl;
    return 0;
}
