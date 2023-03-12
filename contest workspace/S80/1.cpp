#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include "map"
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

        map<int, int> mp;
        for (int i = 0; i < vec.size(); i++)
        {
            mp[vec[i]]++;
        }

        int maxrep = 0;
        for (auto &x : mp)
        {
            maxrep = max(maxrep, x.second);
        }

        cout << vec.size() - maxrep << endl;
    }
    return 0;
}
