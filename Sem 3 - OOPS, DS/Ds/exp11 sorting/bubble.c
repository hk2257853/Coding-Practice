#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arry[100], n;
    printf("Number of elements: \n");
    scanf("%d", &n);
    printf("Enter Elements in array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arry[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arry[j] > arry[j + 1])
                swap(&arry[j], &arry[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arry[i]);
}