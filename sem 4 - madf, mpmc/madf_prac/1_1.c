// BS iterative

#include "stdio.h"

int BS(int arr[], int n, int k)
{
    int s = 0, e = n - 1;
    int mid;

    while (s <= e)
    {
        mid = (s + e) / 2;
        if(arr[mid] == k) return mid;
        if(arr[mid] < k) s = mid + 1;
        else e = mid - 1; 
    }

    return -1;
    
}

int main()
{
    int arr[] = {-1, -2, -8, 0, 1, 2, 3, 4, 5}, n = 9;

    for (int i = 0; i < 9; i++)
    {
        printf("%d for %d \n", BS(arr, n, i), i);
    }
    
    printf("%d", BS(arr, n, -2));
    
    return 0;
}