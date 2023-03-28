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
        int n;
        cin >> n;

        int i = 1;
        int count = 1;
        while (i <= n * n)
        {
            if (i % 2)
                cout << i << " ";
            if (count % 8 == 0)
                cout << endl;
            i++;
            count++;
        }

        i = 1;
        count = 1;
        while (i <= n * n)
        {
            if (i % 2 == 0)
                cout << i << ' ';
            if (count % 8 == 0)
                cout << endl;
            i++;
            count++;
        }
    }
    return 0;
}
