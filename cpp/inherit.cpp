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
    this->age = 0;
    this->id = 0;

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
    this->age = n;
}

void Human::setid(int n)
{
    this->id = n;
}

Student::Student()
{
    this->sid = 0;

    cout<<"A student is successfully created out of a human!"<<endl;
}

Student::~Student()
{
    cout<<"A student is successfully destroyed!"<<endl;
}

Teacher::Teacher()
{
    this->tid = 0;

    cout<<"A teacher is successfully created out of a human!"<<endl;
}

Teacher::~Teacher()
{
    cout<<"A teacher is successfully destroyed!"<<endl;
}

int main(int argc, char *argv[])
{
    Student Daniel;
    Teacher James;
    Daniel.setage(17);
    Daniel.setid(7654);
    cout<<"Student Daniel(id:"<<Daniel.getid()<<") is "<<Daniel.getage()<<" years old!"<<endl;
    James.setage(80);
    James.setid(4242);
    cout<<"Teacher James(id:"<<James.getid()<<") is "<<James.getage()<<" years old!"<<endl;
    cout<<endl;
    cout<<"Daniel loves the James very much!"<<endl;
    return 0;
}
