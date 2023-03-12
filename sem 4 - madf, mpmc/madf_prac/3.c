#include "stdio.h"

// taking right as pivot... 
// just write theory from apna college n keep...

int partition(int arr[], int l, int r)
{

    int p = arr[r], j = l - 1;

    for (int i = l; i < r; i++)
    {
        if(arr[i] < p)
        {
            j++;
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // swap(arr[i], arr[j]);
        }
    }
    
    int temp;
    temp = arr[j + 1];
    arr[j + 1] = arr[r];
    arr[r] = temp;
    // swap(arr[j + 1], p);
    return j + 1;

}

void sort(int arr[], int i, int j)
{
    if(i < j) 
    {
        int pi = partition(arr, i, j);
        sort(arr, i, pi - 1);
        sort(arr, pi + 1, j);
    }
}

int main()
{
    int arr[] = {-1, -2, -8, 0, 1, 2, 3, 4, 5}, n = 9;

    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}