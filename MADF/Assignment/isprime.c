#include "stdio.h"

int count = 0;

int isprime(int n)
{
    count++;
    if(n == 0 || n == 1) return 0;
    int flag = 1;
    for(int i = 2; i < n; i++)
    {
        count++;
        count++; // if check
        if(n % i == 0)
        {
            count++;
            flag = 0;
            break;
        }
    }
    count++;

    return flag;

}

int main()
{
    int n;
    scanf("%d", &n);
    count++;
    if(isprime(n)) printf("Number is prime");
    else printf("Number is not prime");
    printf("\ncount: %d", count);
}
