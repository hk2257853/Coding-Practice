#include "stdio.h"

// need a count for total comparisions

int main()
{
    char T[] = "abcdefg";
    char P[] = "cd";
    int count = 0;
    
    for (int i = 0; i < 8 - 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            count++;
            if(P[j] == T[i + j]);
            else break;
            if(j == 1) printf("1");
        }            
    }    
    
    return 0;
}
