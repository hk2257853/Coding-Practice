#include "iostream"
using namespace std;

int main()
{
    char a[] = "object";
    char b[] = "tcejbo";
    int n = 6;
    cout.fill('*');

    for (int j = n; j > 0; j--)
    {
        cout.write(a, j);
        cout.width(2 * (n - j));
        cout << ""; // printing stars
        cout.write(b, j);
        cout << "\n";
    }

    for (int i = 2; i <= n; i++)
    {
        cout.write(a, i);
        cout.width(2 * (n - i));
        cout << "";
        cout.write(b, i);
        cout << "\n";
    }
}