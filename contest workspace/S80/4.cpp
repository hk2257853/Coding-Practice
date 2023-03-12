#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include "map"
const ll MOD = 1000000007;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        vector<ll> vec;
        ll size, x;
        cin >> size;
        while (size)
        {
            size--;
            cin >> x;
            vec.push_back(x);
        }

        map<ll, ll> mp;
        for (int i = 0; i < vec.size(); i++)
        {
            mp[vec[i]]++;
        }

        ll ans = 0;
        ll mult = 1;
        for (int i = 1; i <= vec.size(); i++)
        {
            if (mp.find(i) != mp.end())
            {
                mult = ((mult % MOD) * (mp[i] % MOD)) % MOD;
                ans = ((ans % MOD) + (mult % MOD)) % MOD;
            }
            else
                break;
        }

        cout << ans << endl;
    }
    return 0;
}
