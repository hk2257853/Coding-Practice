// c the full one not this

#include <iostream>
using namespace std;

class A
{
public:
    virtual void display()
    {
        cout << "Class A" << endl;
    }
};

class B : public A
{
public:
    void display()
    {
        cout << "Class B" << endl;
    }
};

int main()
{
    A *a;
    B b;
    a = &b;
    a->display();
}
