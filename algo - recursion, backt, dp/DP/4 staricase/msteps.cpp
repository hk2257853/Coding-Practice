#include "iostream"
using namespace std;

// its actually fibinacii!!!!
// it was looking a little familiar

int getallpossibilities(int n, int m)
{
    if(n <= 1) return n; // if(n <= 0) return 0 doesn't work
    // 2 possibilities I can take 1, I can take 2
    int sum = 0;
    for (int i = 1; i <= m && i <= n; i++) // i <= n game wrong ans without that...
    {                   // but m > n... so should work? o yeah.. I am doing n - 1!!!
        sum += getallpossibilities(n - i, m);
    }
    return sum;    


    /*
    How I got this:
    Draw a recursion tree for n = 4 and m = 3
    lvl 0 n 1 :
    I see that there r 3 possibilities. 
    go 1 step or 2 step or 3 step...
    so I needed a for loop to get that sum 
    even in 2 cases I can use for loop... But its too simple
    */

}

int main()
{
    int n = 4;
    cout << getallpossibilities(n + 1, 3) << endl;
}