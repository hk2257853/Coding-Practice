#include "iostream"
using namespace std;

int returnnum(int num)
{
    return num;
}

int main()
{
    cout << returnnum(10) << endl;
    int (*ptr)(int) = returnnum;
    int x = ptr(20);
    cout << x;
}