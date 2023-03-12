#include "iostream"
using namespace std;

void bsortd(float pw[], float p[], float w[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(pw[j] < pw[j + 1])  // just taking < makes it in decreasing order
            {
                swap(pw[j], pw[j + 1]);
                swap(p[j], p[j + 1]);
                swap(w[j], w[j + 1]);
            }
        }        
    }
    for (int i = 0; i < n; i++)
    {
        cout << pw[i] << " ";
    }
    
    //  I want in decreasing order... So reversing
    // int a = 0, b = n - 1;
    // while (a <= b)
    // {
    //     swap(pw[a], pw[b]);
    //     swap(w[a], w[b]);
    //     swap(p[a], p[b]);
    //     a++;
    //     b--;
    // }
}

int main()
{
    float W = 50; 
    float w[] = {10, 20, 30 };
    float p[] = {60,  100, 120,};
    
    int n = sizeof(p) / sizeof(p[0]);
    float pw[n];

    for (int i = 0; i < n; i++)
    {
        pw[i] = p[i] / w[i];            
    }

    bsortd(pw, p, w, n);
    
    float ans = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if(W < w[i]) break;
        ans += p[i];
        W -= w[i];
    }
    
    // fraction part
    ans += pw[i] * W;
    cout << ans << endl;

    return 0;
}