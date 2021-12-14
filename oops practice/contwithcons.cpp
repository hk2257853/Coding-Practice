#include "iostream"
using namespace std;

class A
{

public:
    A(int a)
    {
        cout << "Class A";
    }
};

class B
{
    A a1;

public:
    B(int a) : a1(a)
    {
        cout << "Class B";
    }
};

int main()
{
    B b(5);
    // b.
}