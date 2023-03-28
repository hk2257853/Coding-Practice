#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        ll X;
        // X = (C - A) % D + D - B;
        X = (A) % B - (C) % D;
        cout << X << endl;
    }
    return 0;
}
