#include "iostream"
using namespace std;

class str
{
private:
    string x;

public:
    str() {}
    str(string a)
    {
        x = a;
    }

    friend str operator+(str &c1, str &c2)
    {
        str temp;
        temp.x = c1.x + c2.x;

        return temp;
    }

    void Display()
    {
        cout << "x: " << x << endl;
    }
};

int main()
{
    str c1("hi"), c2(" there"), c3;
    c3 = c1 + c2;
    c3.Display();

    return 0;
}
