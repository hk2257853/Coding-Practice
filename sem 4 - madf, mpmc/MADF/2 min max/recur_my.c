#include <stdio.h>

int count = 0;

void minmax(int arr[], int l, int r, int *min, int *max)
{
    if(l == r)
    {
        *min = arr[l];
        *max = arr[r];
        return;
    }

    if(r - l == 1)
    {
        if(arr[l] > arr[r])
        {
            *max = arr[r];
            *min = arr[l];
        }
        else
        {
            *max = arr[l];
            *min = arr[r];
        }
        return;
    }

    int mid = (l + r) / 2;
    int mina, minb, maxa, maxb;
    int *minaptr = mina, *minbptr = minb, *maxaptr = maxa, *maxbptr = maxb;
    // serach left
    return minmax(arr, l, mid - 1, minaptr, minbptr);

    // search right
    return minmax(arr, mid + 1, r, maxaptr, maxbptr);

    // compare min & max returned by the 2
    if(mina < minb) *min = mina;
    else *min = minb;

    if(maxa > maxb) *max = maxa;
    else *max = maxb;
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

    int min, max;
    int *minptr = min, *maxptr = max;

    minmax(arr, 0, n - 1, min, max);

    printf("Max: %d \n Min: %d", max, min);

	return 0;
}
