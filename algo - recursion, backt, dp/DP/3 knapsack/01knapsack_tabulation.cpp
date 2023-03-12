#include "iostream"
using namespace std;

int main()
{
    int capacity = 10;
    int weight[] = {5, 4, 6, 3}, value[] =  {10, 40, 30, 50};
    int arrsize = sizeof(weight) / sizeof(weight[0]);
    int table[arrsize + 1][capacity + 1];

    // base case
    for (int i = 0; i <= capacity; i++) // 1 row 0 (x axis is capacity)
    {
        table[0][i] = 0;
    }
    for (int i = 0; i <= arrsize; i++)
    {
        table[i][0] = 0;
    }
    
    for (int i = 1; i <= arrsize; i++) // i j will start from 1 as base case is already taken
    {
        for (int j = 1; j <= capacity; j++)
        {
            // I dont take it
            int donot_takevalue = table[i - 1][j];
            // I take it
            int takevalue = 0;
            if (j >= weight[i - 1]) // can take only if capacity is more than it. i - 1 as 1st one I filled with base case so...
            { // Aditya verma used recursive code to get this (his is a little different though)
                takevalue = value[i - 1];
                int remainingcap = j - weight[i - 1]; // sub 
                takevalue += table[i - 1][remainingcap]; // get max value for it and take to take. i -1 part... the value remains same.. better to remove it n go for 1D matrix
            }
            
            // put max of them in matrix
            table[i][j] = max(takevalue, donot_takevalue);
        }
    }
    cout << table[arrsize][capacity] << endl << endl;

    // print
    for (int i = 0; i <= arrsize; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;            
    }
    return 0;
}

// coding part is very easy.
// Need to comfortable with 2D matrix
// Just see what I want in words n then its very easy to access that.