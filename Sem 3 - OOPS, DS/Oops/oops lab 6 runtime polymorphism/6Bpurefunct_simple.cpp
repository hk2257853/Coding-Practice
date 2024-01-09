// Abstraction

#include <iostream>
using namespace std;

class A
{
public:
    virtual void display() = 0;
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
    B b;
    b.display();
}

// pure virtual function: a virtual function that is declared in the base class but has no definition, "must" be defined in the derived class
// can't make obj of abs class, can make pointer though

// abstract class: a class that contains atleast one pure virtual function
// showing only essential details to outside world