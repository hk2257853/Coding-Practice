#include "iostream"
using namespace std;

int main()
{
    int table[3][3];
    // fill matrix with 0
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j] = 0;
        }
    }

    // fill 1st row with 1
    // for (int i = 0; i < 3; i++) // I want to move left in 1st row...
    // {
    //     table[0][i] = 1;
    // }

    // fill 1st column with 1
    for (int i = 0; i < 3; i++)
    {
        table[i][0] = 1;
    }
    

    // print
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;            
    }
}