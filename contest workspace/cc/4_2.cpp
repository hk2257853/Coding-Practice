#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll countElementsLessThanX(ll x) {
    ll low = 1, high = x, ans = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll x;
        cin >> x;

        ll ans = countElementsLessThanX(x);

        // Adjust the answer based on x and ans
        if (x % 2 == 0) {
            if (ans % 2 == 1) {
                ans--;
            }
        } else {
            if (ans % 2 == 0) {
                ans--;
            }
        }

        // Output the adjusted answer
        cout << (ans + 1) / 2 << endl;
    }

    return 0;
}
