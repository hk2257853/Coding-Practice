#include "stdio.h"

int BS(int arr[], int n, int k, int s, int e)
{
    // if(s <= e) - this doesn't work for some reason...

    if(e >= s) 
    {
    int mid = (s + e) / 2;
    if(arr[mid] == k) return mid;
    if(arr[mid] < k) return BS(arr, n, k, mid + 1, e);
    return BS(arr, n , k, s, mid - 1);    
    }
    return -1;
}


int main()
{
    int arr[] = {-1, -2, -8, 0, 1, 2, 3, 4, 5}, n = 9;

    for (int i = 0; i < 9; i++)
    {
        printf("%d for %d \n", BS(arr, n, i, 0, 8), i);
    }
    
    printf("%d", BS(arr, n, -2, 0, 8));
    
    return 0;
}
