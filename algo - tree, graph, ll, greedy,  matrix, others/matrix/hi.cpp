#include "iostream"
using namespace std;

int matrix[3][3];
// finally ok with matrix
int main()
{
    int x = 1, y = 1;
    matrix[x][y] = 1;
    matrix[x - 1][y - 1] = 10; // put at 1 step left n 1 step up
    matrix[x + 1][y] = 50;
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