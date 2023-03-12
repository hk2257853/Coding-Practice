#include "iostream"
using namespace std;

long long fib(long long n)
{
    // base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long table[1000];
    table[0] = 0;
    table[1] = 1;

    for (int i = 2; i <= n; i++)
        table[i] = table[i - 1] + table[i - 2];

    return table[n];
    
}

int main()
{
    cout << fib(20);
}