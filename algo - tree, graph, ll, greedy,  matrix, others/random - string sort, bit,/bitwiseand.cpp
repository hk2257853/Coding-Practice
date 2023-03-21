#include "iostream"
using namespace std;

int main()
{
    while (1)
    {
        int a = 1, b = 10;
        cout << "Enter data\n";

        cin >> a >> b;
        int c = a & b;
        cout << c << endl;
    }

    return 0;
}