#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include <math.h>
bool isperfectsqare(ll n)
{
    ll x = sqrt(n);
    if (x * x == n)
        return true;
    return false;
}

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		t--;
        int size;
        cin >> size;
        ll sum = 0, num;
        while (size--)
        {
            cin >> num;
            sum += num;
        }

        if(isperfectsqare(sum))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
	}
	return 0;
}
