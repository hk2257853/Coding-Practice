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

    void operator>(str &c2)
    {
        if (x.size() > c2.x.size()) // doing x>c1.c doesn't work.
        {
            cout << "c1 is greater than c2";
        }
        else if (x.size() < c2.x.size())
        {
            cout << "c2 is greater than c1";
        }
        else
        {
            cout << "They are equal";
        }
    }
};

int main()
{
    str c1("hi"), c2(" there"), c3;
    c3 = c1 + c2;
    c3.Display();
    c1 > c2;

    return 0;
}
