#include <stdio.h>

int count = 0;

void merge(int arr[], int l, int r, int mid)
{
    count++; // its recursive... so each of these will be called again n again
    int merged[r - l + 1];
    count++;
    int idx1 = l;
    count++;
    int idx2 = mid + 1;
    count++;
    int x = 0;
    count++;
    while(idx1 <= mid && idx2 <= r)
    {
        count++;
        count++;
        count++;
        if(arr[idx1] <= arr[idx2]) merged[x++] = arr[idx1++];
        else merged[x++] = arr[idx2++];
    }
    count++;

    while(idx1 <= mid) {
        count++;
        count++;
        merged[x++] = arr[idx1++];
    }
    count++;
    while(idx2 <= r){
        count++;
        count++;
        merged[x++] = arr[idx2++];
    }
    count++;

    for(int i = 0, j = l; i < r - l + 1; i++, j++) {
        count++;
        count++;
        count++;
        arr[j] = merged[i];
    }
    count++;
}

void divide(int arr[], int l, int r)
{
    count++;
    if(l >= r) return;
    count++;
    int mid = (l + r) / 2;
    count++;
    divide(arr, l, mid);
    count++;
    divide(arr, mid + 1, r);
    merge(arr, l, r, mid);
    count++;
}

int main()
{
    int n = 6;
    printf("Enter Total elements: ");
    scanf("%d", &n);
    printf("\nEnter elements: ");
    int arr[n];
    for(int i = 0; i < n; i++) 
    {
        count++;
        scanf("%d", &arr[i]);
    }
    divide(arr, 0, n - 1);
    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
    {
        count++;
        printf("%d ", arr[i]);
    }
    printf("\nCount:%d", count);
}
