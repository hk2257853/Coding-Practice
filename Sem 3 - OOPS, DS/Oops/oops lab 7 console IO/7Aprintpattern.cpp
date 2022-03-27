#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    cout.precision(4);
    cout.setf(ios::showpoint);
    cout.setf(ios::internal, ios::adjustfield);

    for (int i = 1; i < 6; i++)
    {
        cout.setf(ios::showpos);
        cout.fill('.');
        cout.width(5);
        cout << i;
        cout.fill('*');
        if (i == 4)
            cout.fill('<');
        if (i == 5)
            cout.fill('>');
        cout.unsetf(ios::showpos);
        cout.width(10);
        cout << "";
        cout << 1 / sqrt(i);
        cout << "\n";
    }
}

// +...1**********1.0000
// +...2*********0.70711

// +...1***********1.000
// +...2**********0.7071