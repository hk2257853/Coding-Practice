#include "stdio.h"

void merge(int arr[], int s, int e, int mid)
{
    int merged[e - s + 1];
    int a = s;
    int b = mid + 1; // + 1
    int c = 0;
    while (a <= mid && b <= e)
    {
        if(arr[a] < arr[b]) 
        {
            merged[c] = arr[a];
            a++; // I had put this below
        }
        else
        {
            merged[c] = arr[b];
            b++;
        } 
        c++;
    }

    while (a <= mid)
    {
        merged[c] = arr[a];
        a++;
        c++;
    }
    
    while (b <= e)
    {
        merged[c] = arr[b];
        b++;
        c++;
    }

    // for (int i = 0; i < e - s + 1; i++)
    // {
    //     arr[s + i] = merged[i];
    // }
        
        for(int i = 0, j = s; i < e - s + 1; i++, j++) {
        arr[j] = merged[i];
    }
    
}

void divide(int arr[], int s, int e)
{
    if(s >= e) return;
    int mid = (s + e) / 2;
    divide(arr, s, mid); // mid not mid - 1. I am diving in 2 equal halves here!
    divide(arr, mid + 1, e);
    merge(arr, s, e, mid);

}

int main()
{
    int arr[] = {-1, -2, -8, 0, 1, 2, 3, 4, 5}, n = 9;

    divide(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}