#include "stdio.h"

int count = 0;

int main()
{
    int n, ans = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        count++; // for i
        ans *= i;
        count++; // for above calc
    }
    count++; // for last instance of i

    printf("factorial: %d\n", ans);
    printf("count: %d", count);
}
