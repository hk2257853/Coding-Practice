#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

// BIG POSSIBLE MISTAKE: Not using long long!!!! This time I was lucky!
int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        vector<int> vec1, vec2;
        int size, x, k, size2;
        cin >> size >> k;
        size2 = size;
        while (size)
        {
            size--;
            cin >> x;
            vec1.push_back(x);
        }

        while (size2)
        {
            size2--;
            cin >> x;
            vec2.push_back(x);
        }

        ll ans = 0, sum = 0;
        int bmax = 0;
        for (int i = 0; i < vec2.size(); i++)
        {
            if(k == 0) break;
            sum += vec1[i];
            k--;
            bmax = max(bmax, vec2[i]);
            ans = max(ans, sum+k*bmax);
        }
        cout << ans << endl;
    }
    return 0;
}
