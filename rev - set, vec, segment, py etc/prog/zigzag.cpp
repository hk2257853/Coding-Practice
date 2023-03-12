#include "iostream"
using namespace std;

// we won this! (me & shriteen)

int main()
{
    int n;
    cin >> n;
    
    for (int j = 1; j < n; j++)
    {
        if ((j + 1) % 4 == 0) cout << "*";
        else cout << " ";
    }
    cout << endl;
    for (int j = 0; j < n; j++)
    {
        if (j % 2) cout << "*";
        else cout << " ";
    }
    cout << endl;
    for (int j = 0; j < n; j++)
    {
        if (j % 4 == 0) cout << "*";
        else cout << " ";
    }
    
    

}