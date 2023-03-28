#include "iostream"
using namespace std;

// containership: class A is a member of class B

class A
{

public:
    void a()
    {
        cout << "Class A" << endl;
    }
};

class B
{
public: // protected didn't work
    A a1;

public:
    void b()
    {
        a1.a();
        cout << "Class B" << endl;
    }
};

int main()
{
    B b;
    b.b();
    b.a1.a();
}