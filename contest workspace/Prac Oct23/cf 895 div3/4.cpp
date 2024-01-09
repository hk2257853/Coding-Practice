#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include <math.h>

ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		t--;
		ll n, x, y;
		cin >> n >> x >> y;

		ll Tx = n / x, Ty = n / y;
		ll Txy = n / lcm(x, y);
		Tx -= Txy;
		Ty -= Txy;

		// sum
		ll sumy= Ty * (Ty+1)/2;
		ll sumx = (n + n - Tx + 1) * Tx / 2; // chat gpt helped to get this formula (n = 15, k = 3. sum = 15 + 14 + 13)

		cout << sumx - sumy << endl;
				
	}
	return 0;
}
