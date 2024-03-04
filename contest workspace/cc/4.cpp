#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include "math.h"
ll countElementsLessThanX(ll x) {
    ll n = 1;
    while ((long long)n * n <= x) {
        n++;
    }

    return n - 1;
}

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		t--;
        ll x;
        cin >> x;
        ll ans = countElementsLessThanX(x);
        
        if(x % 2 == 0){
            if(ans % 2 == 1) ans--;
        }
        else {
            if(ans % 2 == 0) ans--;
        }
        cout << ans << " " << ceil((double)ans / 2) << endl;    
	}
	return 0;
}
