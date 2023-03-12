#include "iostream"
using namespace std;

int lis(int arr[], int size, int index)
{
    if(size == 1) return 1;

    if(arr[index + 1] > arr[index])
    {
        return 1 + lis(arr, size - 1, index - 1);
    }
    return lis(arr, size - 1, index - 1); // simply return... no need to include
}

int main()
{
    int arr[] = {3, 10, 1, 2, 20};
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    cout << lis(arr, arrsize, arrsize);

    return 0;
}