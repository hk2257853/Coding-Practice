#include <iostream>
using namespace std;

// constructor: a special member function that is called automatically when an object is created.
class calc
{
private:
    int x, y;

public:
    calc() // default. Note: must be declared if there is a parameterised constructor
    {
        cout << "This program prints the sum" << endl;
    }
    calc(int a, int b) // parameterised
    {
        x = a;
        y = b;
        cout << "Sum is: " << x + y;
    }
};

int main()
{
    calc b; // default constructor will be called
    int x, y;
    cout << "Enter first value" << endl;
    cin >> x;
    cout << "Enter second value" << endl;
    cin >> y;
    calc a(x, y); // default won't be called if parameterised is called

    return 0;
}
