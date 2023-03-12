#include "iostream"
using namespace std;

int memoized[1000];

long long fib(long long n)
{
    // base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    if(memoized[n] != 0) return memoized[n];
    else
    {
        long long x = fib(n - 1) + fib(n - 2); // just storing it once calculated.
        memoized[n] = x; 
        return x;
    }
    // based on relation between prob and sub prob
}

int main()
{
    cout << fib(20);
}