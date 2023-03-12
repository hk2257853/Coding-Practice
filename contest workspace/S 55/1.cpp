#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include<numeric>
using ll = long long;

int main() 
{
	int t;
	cin >> t;
	while(t)
	{
	    t--;
	    ll n, k;
		cin >> n >> k;
		if(n >= k * (k + 1) / 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
