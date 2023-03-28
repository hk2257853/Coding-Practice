#include <iostream>
using namespace std;

// A very simple bad program to understand oops. Data part is like structure for public
// here everything is public which is dangerous(if 2 variables have same name it will be an issue, especially if
//  its like UE4 where so many .cpp oops files  r there).

// if I make the variables or functions private here, I won't be able to access using object.
// So I'll need getters and setters.
class calc
{
public:
    int x, y;
    void sum()
    {
        cout << x + y;
    }
};

int main()
{
    calc a;
    cout << "Enter first value" << endl;
    cin >> a.x;
    cout << "Enter second value" << endl;
    cin >> a.y;

    a.sum();
    return 0;
}
