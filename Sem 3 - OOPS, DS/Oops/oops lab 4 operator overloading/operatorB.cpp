#include "iostream"
using namespace std;

class num
{
private:
    int x, y;

public:
    num() {}
    num(int a, int b)
    {
        x = a;
        y = b;
    }

    num operator*(num &c2)
    {
        num temp;
        temp.x = x * c2.x;
        temp.y = y * c2.y;
        return temp;
    }

    // if we have inbuilt type and class, we use friend (chat gpt: allows you to access the private members of the num class from the non-member function operator+)
    friend num operator+(int c1, num &c2) // if I write  int &c1, it gives error
    {
        num temp;
        temp.x = c1 + c2.x;
        temp.y = c1 + c2.y;
        return temp;
    }

    friend num operator+(num &c2, int c1);

    void Display()
    {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
};

num operator+(num &c2, int c1)
{
    num temp;
    temp.x = c1 + c2.x;
    temp.y = c1 + c2.y;
    return temp;
}

int main()
{
    num c1(5, 8), c2(1, 3), c3;
    cout << "Multiplication of 2 objects:\n";
    c3 = c1 * c2;
    c3.Display();

    cout << "Addition of integer and object:\n";
    c3 = 5 + c1;
    c3.Display();

    cout << "Addition of object and integer:\n";
    c3 = c1 + 7;
    c3.Display();

    return 0;
}
