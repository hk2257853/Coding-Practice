#include "iostream"
using namespace std;

class Math
{
    int num1, num2, numcons;

public:
    int publicnum;
    Math() {}

    Math(int x)
    {
        numcons = x;
    }

    Math(Math &ob)
    {
        publicnum = ob.publicnum;
    }

    int sum()
    {
        return num1 + num2;
    }

    int getnum()
    {
        return numcons;
    }

    void setnums(int a, int b);
};

// return types 1st
void Math::setnums(int a, int b)
{
    num1 = a;
    num2 = b;
}

void exception_test()
{
    try
    {
        if (false)
            10 / 0;
        else
            throw 1;
    }
    catch (int e)
    {
        cout << "Error";
    }
}

int main()
{
    Math m, Am[2];
    m.setnums(1, 2);
    cout << m.sum() << endl;

    Am->setnums(8, 2); // index 0 got set ig
    // cout << Am->sum() << endl;

    Am[1].setnums(6, 9);
    cout << Am[0].sum() << " " << Am[1].sum() << endl;

    Math constry(5);
    cout << constry.getnum() << endl;

    constry.publicnum = 10; // public member can be accessed outside the class
    Math copyy(constry);
    cout << copyy.publicnum << endl;
}
