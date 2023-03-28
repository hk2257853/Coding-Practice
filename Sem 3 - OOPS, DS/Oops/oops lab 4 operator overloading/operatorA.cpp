#include "iostream"
using namespace std;

// I wanna do a++ where a is an object of class unary. (internally I'll increment the value of variables, like here x, by 1)
class unary
{
private:
    int x;

public:
    unary() {}
    unary(int a)
    {
        x = a;
    }

    unary operator++() // after removing int as paramenter it worked!! understand this topic further
    {
        unary temp;
        temp.x = ++x;
        return temp;
    }

    // for post increment, pass int
    void operator++(int) // after putting int as paramenter it worked!! understand this topic further
    {
        this->x++; // works too
    }

    unary operator--()
    {
        unary temp;
        temp.x = --x;
        return temp;
    }

    unary operator--(int)
    {
        unary temp;
        temp.x = x--;
        return temp;
    }

    void Display()
    {
        cout << "x: " << x << endl;
    }
};

int main()
{
    unary c1(5);
    ++c1;
    c1++;
    c1.Display();
    --c1;
    c1--;
    c1.Display();

    return 0;
}
