#include "iostream"
using namespace std;

int matrix[3][3];
// finally ok with matrix
int main()
{
    // 1st row
    for (int i = 0; i < 3; i++)
    {
        matrix[i][1] = 10;
    }

    for (int i = 0; i < 3; i++) // go through each row (go down)
    {
        for (int j = 0; j < 3; j++) // print the colum (go right)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
        
    return 0;
}