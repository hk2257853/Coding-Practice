#include <iostream>
using namespace std;

int main()
{
    int *t = new int[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> t[i];
    }
    cout << "Output" << endl;
    cout << *(t + 1) << endl;
    cout << t[2] << endl;
}
