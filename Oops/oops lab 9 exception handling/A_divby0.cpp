#include "iostream"
using namespace std;

void divide(int a, int b)
{
    try
    {
        if (b != 0)
            cout << "Division is: " << a / b;
        else
            throw(b);
    }
    catch (int c)
    {
        cout << "Caught exception in division funtion" << endl;
        throw; // rethrow
    }
}

// We throw excetion multiple times to know where the error occured.

int main()
{
    int a, b;
    cout << "Enter numbers:" << endl;
    cin >> a >> b;

    try
    {
        divide(a, b);
    }
    catch (int d)
    {
        cout << "Exection caught in main";
    }
}