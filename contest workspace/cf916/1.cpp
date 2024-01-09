#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
#include "unordered_map"
using ll = long long;

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		t--;
        int n;
        string s;
        cin >> n >> s;

        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int count = 0;
        for(auto x:mp)
        {
            if(x.second >= x.first-'A'+1) count++;
        }
        cout << count << endl;
	}
	return 0;
}
