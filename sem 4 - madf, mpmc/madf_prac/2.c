#include "stdio.h"

// make m recursion knowledge more clear

void minmax(int arr[], int s, int e, int *min, int *max)
{
    if(s == e)
    {
        *max = *min = arr[s];
        return;
    }
    if(s == e -1)
    {
        if (arr[s] > arr[e])
        {
            *max = arr[s];
            *min = arr[e];
        }
        else
        {
            *min = arr[s];
            *max = arr[e];
        }        
        return;
    }

    int mid = (s + e) / 2;
    int min1 = *min, max1 = *max;
    minmax(arr, s, mid - 1, min, max);
    minmax(arr, mid + 1, e, &min1 , &max1);

    if(*min > min1) *min = min1;
    if(*max < max1) *max = max1;

}

int main()
{
    int arr[] = {-1, -2, -8, 0, 1, 2, 3, 4, 5}, n = 9;
    int min, max;
    minmax(arr, 0, n - 1, &min, &max);
    printf("\nMin = %d",min);
	printf("\nMax = %d",max);

}