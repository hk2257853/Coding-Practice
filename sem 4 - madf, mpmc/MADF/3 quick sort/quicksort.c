#include <stdio.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }        
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
    
}

void quicksort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
}

int main()
{
    printf("Enter total elements: ");
    int n = 6;
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    quicksort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

