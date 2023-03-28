#include <iostream>
using namespace std;

class calc
{
public:
    // call by reference: it will not create a copy of the variable. It will directly use the variable.
    int sum(int &x, int &y)
    {
        return x + y;
    }
};

int main()
{
    calc cal;
    int a, b;
    cout << "Enter first digit\n";
    cin >> a;
    cout << "Enter second digit\n";
    cin >> b;

    cout << "The sum is: " << cal.sum(a, b);
    return 0;
}