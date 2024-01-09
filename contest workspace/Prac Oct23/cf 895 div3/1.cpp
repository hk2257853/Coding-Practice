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
		int a,b,c;
		cin >> a >> b >> c;
        if(b > a) swap(a, b);
		int ans = 0;

        while(a > b && a > 0)
        {
            a -= c;
            b += c;
            ans++;
        }

        // if(a != b && abs(a - b) > c) ans++;
		
        cout << ans << endl;
	}
	return 0;
}
