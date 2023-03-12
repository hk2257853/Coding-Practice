#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include<numeric>
using ll = long long;

// BF gives TLE

int main() 
{
	int t;
	cin >> t;
	while(t)
	{
	    t--;
        vector<ll> Tvec;
        ll size, x, size2;
        cin >> size;
        size2 = size;
        while (size)
        {
            size--;
            cin >> x;
            Tvec.push_back(x);
        }

        vector<ll> Pvec, ans(Tvec.size(), 0);
        while (size2)
        {
            size2--;
            cin >> x;
            Pvec.push_back(x);
        }

        ll count = 0;
        while (count < Tvec.size())
        {
            for (int i = 0; i < Tvec.size() - count; i++)
            {
                ans[i + count] += min(Tvec[i], Pvec[i + count]);
                Tvec[i] -= min(Tvec[i], Pvec[i + count]);
            }
            count++;
        }
        
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;

        
        

	}
	return 0;
}
