#include "stdio.h"
#include <stdlib.h>

// matrix using dma is req
// in cpp i could have used vector... still its ok...
// array gets passed by reference but matrix don't!
// 80% on my own. The format is fixing in my head

int isSafe(int** arr, int x, int y, int n)
{
    // checking the col 0 till x (now need to check below x as nothing there)
    for (int row = 0; row < x; row++)    
        if(arr[row][y]) return 0;

    int row = x;
    int col = y;

    // check upper left diagonal
    for (row, col; row >= 0 && col >= 0; row--, col--)
    {
        if(arr[row][col]) return 0;
    }

    // check upper right diagonal
    row = x, col = y;
    for (row, col; row >= 0 && col < n; row--, col++)
    {
        if(arr[row][col]) return 0;
    }
    
    return 1;
}

int nq(int** arr, int x, int n)
{
    if(x >= n) return 1;

    for (int i = 0; i < n; i++)
    {
        if(isSafe(arr, x, i, n))
        {
            arr[x][i] = 1;
            if(nq(arr, x + 1,n)) return 1;
            arr[x][i] = 0;
        }
        //return -1; // not req?
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    // int arr[n][n];
    int** arr;
    arr = malloc(n * sizeof *arr);
    for (int i=0; i<n; i++)
    {
        arr[i] = malloc(n * sizeof *arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }        
    }
    
    nq(arr, 0, n);
    //printf("hi");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }        
        printf("\n");
    }

}