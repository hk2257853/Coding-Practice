#include "iostream"
using namespace std;

class io
{
private:
    int x;

public:
    friend istream &operator>>(istream &in, io &o)
    {
        cout << "Enter value" << endl;
        in >> o.x;
        return in;
    }

    friend ostream &operator<<(ostream &ot, io &i);
};

ostream &operator<<(ostream &ot, io &i)
{
    cout << "output: " << endl;
    ot << i.x;
    return ot;
}

int main()
{
    io c1;
    cin >> c1; // >> is binary or unary here?
    cout << c1;

    return 0;
}
