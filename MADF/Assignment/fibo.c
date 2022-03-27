#include "stdio.h"

int count = 0;

int main()
{
    int a = 0, b = 1, c;
    int n;
    scanf("%d", &n);
    count++;
    if(n >= 1) printf("0 ");
    count++;
    if(n >= 2) printf("1 ");
    for(int i = 0; i < n - 2; i++)
    {
        count++;
        printf("%d ", a + b);
        count++;
        c = a;
        count++;
        a = b;
        count++;
        b = c + b;
        count++;
    }
    count++;
    printf("\ncount: %d", count);
}
