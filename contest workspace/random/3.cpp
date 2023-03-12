#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
#include "map"
using ll = long long;

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

        // failed case: 1 1 1 1 1 2
        if (mp.size() % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            bool isduplicate = false;
            for (auto &x : mp)
            {
                if (x.second > 1)
                    isduplicate = true;
            }

            if (isduplicate)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
