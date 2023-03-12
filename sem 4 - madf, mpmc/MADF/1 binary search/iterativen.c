#include <stdio.h>

int count = 0;

int binsearch(int arr[], int n, int num)
{
    int l = 0, r = n - 1, mid;
    while (l <= r) // doen't work properly without equal to
    {
        count++;

        count++;
        mid = (l + r) / 2;
        count++;
        if(arr[mid] == num) return mid; // arr[mid] not mid!

        count++;
        if(arr[mid] > num)
        {
            count++;
            r = mid - 1;
        }
        else
        {
            count++;
            l = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    printf("Enter total elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        count++;
        scanf("%d", &arr[i]);
        count++;
    }
    count++;

    printf("Enter element to search: ");
    int num;
    scanf("%d", &num);
    printf("\n%d", binsearch(arr, n, num));
    printf("\nCount:%d ", count);

    return 0;
}
