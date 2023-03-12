#include "stdio.h"

int count = 0;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    int b[n][n], c[n][n];

    // input
    for(int i = 0; i < n; i++)
    {
        count++;  // for i
        count++; // for  the below for loop
        for(int j = 0; j < n; j++)
        {
            count++; // for j
            count++;
            scanf("%d ", &a[i][j]);
        }
        count++; // last inst of j
    }
    count++;

    for(int i = 0; i < n; i++)
    {
        count++;
        for(int j = 0; j < n; j++)
        {
            count++;
            count++;
            scanf("%d ", &b[i][j]);
        }
        count++;
    }
    count++;

    // mult
    for(int i = 0; i < n; i++)
    {
        count++;
        for(int j = 0; j < n; j++)
        {
            count++;
            count++; // for initialisation to 0
            count++; // for the below for loop
            c[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                count++;
                c[i][j] += a[i][k] * b[k][j];
                /*
                    thinking
                    i want to traverse all cell of ans
                    for mult traverse 1 row & 1 col in A & B
                    thus k. 1 row & 1 col. so one one const in each (i,k)

                    using this bigger pic, get the ans
                */
            }
            count++;
        }
        count++;
    }
    count++;

    // print matrix c
    for(int i = 0; i < n; i++)
    {
        count++;
        for(int j = 0; j < n; j++)
        {
            count++;
            printf("%d ", c[i][j]);
        }
        count++; // for last inst of j
        count++;
        printf("\n");
    }
    count++;

    printf("\ncount: %d", count);
    return 0;
}
