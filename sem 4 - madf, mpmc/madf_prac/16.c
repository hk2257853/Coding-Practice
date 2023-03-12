#include "stdio.h"

void FP(char p[], int n, int prefix[])
{
    prefix[0] = 0;
    for (int i = 1, j = 0; i < n; i++)
    {
        while (p[i] == p[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }

        j = 0;
        prefix[i] = j;        
    }
    
}

int main()
{
    char p[] = "ab", t[] = "acbdabz"; // acbdabz
    int ps = sizeof(p) / sizeof(p[0]), ts = sizeof(t) / sizeof(t[0]);
    int i = 0, j = 0;
    ps--;
    ts--;
    int prefix[ps];
    //printf("%d", ps);
    FP(p, ps, prefix);

    int index = -1;

    for (int i = 0; i < ts; i++)
    {
        
        if(t[i] == p[j]) 
        {
            i++;
            j++;
        }
        else
        {
            if(j!= 0) j = prefix[j - 1]; // j or j - 1?
            else i++;
        }
        if(j == ps) 
        {
            //printf("%d", i);
            index = i - ps + 1; // had to do +1
            break;
        }
    }
    
    printf("%d", index);
    



}