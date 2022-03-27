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
        int check = i;
        while (check > 0 && arry[check - 1] > arry[check])
        {
            swap(&arry[check - 1], &arry[check]);
            check--;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arry[i]);

    return 0;
}