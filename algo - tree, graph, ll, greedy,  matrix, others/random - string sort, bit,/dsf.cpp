#include <iostream>
using namespace std;

int main()
{
    int n = 1;
    while (n > 0)
    {
        int C = 30, D = 45;

        int suma = 360;

        int X1, X2;
        X1 = suma + (2 * D);
        X2 = suma + C + D;
        if (suma < 150)
        {
            X2 = X2 + D;
        }

        if (X1 > X2)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";

        n--;
    }
    return 0;
}
