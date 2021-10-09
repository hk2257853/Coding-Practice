#include <stdio.h>

void revereseArray(int arr[], int start, int end)
{
    int temp;
    static sum = 0;
    if (start >= end)
        return;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    revereseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int sumArray(int arr[], int size)
{
    if (size <= 0)
        return 0;

    return (sumArray(arr, size - 1) + arr[size - 1]);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    printArray(arr, 6);
    revereseArray(arr, 0, 5);
    printf("Reversed array is \n");
    printArray(arr, 6);

    printf("\nSum of items: %d \n", sumArray(arr, 6));
    return 0;
}
