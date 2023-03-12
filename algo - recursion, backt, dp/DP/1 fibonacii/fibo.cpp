#include "iostream"
using namespace std;

// recursive program to print nth fibo

/////// Interesting:
// Doesn't output for n = 50+   memoised one shows ans... but wrong lol!

long long fib(long long n)
{
    // base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // based on relation between prob and sub prob
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(51);
}