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

        vector<int> vec;
        int size, x;
        cin >> size;
        while (size)
        {
            size--;
            cin >> x;
            vec.push_back(x);
        }

        sort(vec.begin(), vec.end());

        ll l = 0, r = 0, ind = 1, minlr = INT_MAX;

        for (int i = 1; i < vec.size() - 1; i++)
        {
            l = vec[i] - vec[i - 1];
            r = vec[i + 1] - vec[i];
            if (l + r < minlr)
            {
                minlr = l + r;
                ind = i;
            }
        }

        ll mean = (vec[ind - 1] + vec[ind] + vec[ind + 1]) / 3;
        ll median = vec[ind];
        ll ans = 3 * (mean - median);
        cout << ans << endl;
    }
    return 0;
}
