#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include <climits>

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;

        int size, x, y;
        cin >> size;
        int min_dist = INT_MAX;
        while (size)
        {
            size--;
            cin >> x >> y;
            if (y % 2 == 1) y++;
            int dist = x + (y - 2) / 2;
            if (dist < min_dist)
            {
                min_dist = dist;
            }
        }

        cout << min_dist << endl;
    }
    return 0;
}
