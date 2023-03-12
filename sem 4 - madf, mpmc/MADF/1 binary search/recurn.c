#include <stdio.h>

int count = 0;

int binarySearch(int arr[], int l, int r, int x)
{
    count++;
	if (r >= l) {
        count++;
		int mid = l + (r - l) / 2;

        count++;
		if (arr[mid] == x)
			return mid;

        count++;
		if (arr[mid] > x)
        {
            count++;
			return binarySearch(arr, l, mid - 1, x);
        }
        count++;
		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}

int main(void)
{
    int n;
    printf("Enter total elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        count++;
        count++;
        scanf("%d", &arr[i]);
    }
    count++;

    int num;
    scanf("%d", &num);
    printf("\n%d", binarySearch(arr, 0, n - 1, num));
    printf("\nCount:%d", count);

    return 0;
}
