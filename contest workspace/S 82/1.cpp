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

        vector<int> vec;
        int size, x;
        cin >> size;
        int size2 = size;
        while (size)
        {
            size--;
            cin >> x;
            vec.push_back(x);
        }

        vector<int> vec2;
        int x2;
        while (size2)
        {
            size2--;
            cin >> x2;
            vec2.push_back(x2);
        }

        bool flag = true;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == 1 && vec2[i] == 0)
                flag = false;
            if (vec[i] == 1)
                count1++;
            if (vec2[i] == 1)
                count2++;
        }

        // damn, can't believe this is the TC most people r stuck on! i < j < k and not i,j,k
        if (vec[0] == 0 && vec2[0] == 1)
            flag = false;
        int n = vec.size();
        if (vec[n - 1] == 0 && vec2[n - 1] == 1)
            flag = false;

        if (count1 == 0 && count2 != 0)
            flag = false;

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
