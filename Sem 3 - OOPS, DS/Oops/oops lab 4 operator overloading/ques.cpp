#include "iostream"
using namespace std;

class io
{
private:
    int x;

public:
    friend void operator>>(istream &in, io &o)
    {
        cout << "Enter value" << endl;
        in >> o.x;
        //return in;
    }

    //Question: Work without returning too. Then why to?

    friend void operator<<(ostream &ot, io &i)
    {
        cout << "output" << endl;
        ot << i.x;
        //return ot;
    }
};

int main()
{
    io c1;
    cin >> c1;
    //cin is object. >> is operator.
    cout << c1;

    return 0;
}
