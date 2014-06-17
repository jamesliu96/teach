#include <iostream>

using namespace std;

class Human
{
private:
    int age;
    int id;
public:
    Human();
    ~Human();
    int getage();
    int getid();
    void setage(int n);
    void setid(int n);
};

class Student:public Human
{
private:
    int sid;
public:
    Student();
    ~Student();
};

class Teacher:public Human
{
private:
    int tid;
public:
    Teacher();
    ~Teacher();
};

Human::Human()
{
    age = 0;
    id = 0;

    cout<<"A human is successfully created!"<<endl;
}

Human::~Human()
{
    cout<<"A human is successfully destroyed!"<<endl;
}

int Human::getage()
{
    return age;
}

int Human::getid()
{
    return id;
}

void Human::setage(int n)
{
    age = n;
}

void Human::setid(int n)
{
    id = n;
}

Student::Student()
{
    sid = 0;

    cout<<"A student is successfully created out of a human!"<<endl;
}

Student::~Student()
{
    cout<<"A student is successfully destroyed!"<<endl;
}

Teacher::Teacher()
{
    tid = 0;

    cout<<"A teacher is successfully created out of a human!"<<endl;
}

Teacher::~Teacher()
{
    cout<<"A teacher is successfully destroyed!"<<endl;
}

int main(int argc, char *argv[])
{
    Student Daniel;
    Teacher Bitch;
    Daniel.setage(17);
    Daniel.setid(7654);
    cout<<"Student Daniel(id:"<<Daniel.getid()<<") is "<<Daniel.getage()<<" years old!"<<endl;
    Bitch.setage(80);
    Bitch.setid(4242);
    cout<<"Teacher Bitch(id:"<<Bitch.getid()<<") is "<<Bitch.getage()<<" years old!"<<endl;
    cout<<endl;
    cout<<"Daniel loves the old Bitch so much!"<<endl;
    return 0;
}
