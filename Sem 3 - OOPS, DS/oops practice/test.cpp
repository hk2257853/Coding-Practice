#include "iostream"
using namespace std;

int main()
{
    int a = 10;
    int *x = &a;
    int *y = x;
    int b = *y;
    cout << b;
}