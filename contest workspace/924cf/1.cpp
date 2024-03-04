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
        int x, y;
        cin >> x >> y;
        
        bool flag = false;
        // stage 1
        int a = x /2, b = x - x/2;
        int c = y, d = y;

        // cout << a << " " << b << endl;
        if((a != 0 && b != 0) && (a + b != x && c != y) && (a != y && c + d != x)) flag = true;

        a = y /2, b = y - y/2;
        c = x, d = x;

        if((a != 0 && b != 0) && (a + b != x && c != y) && (a != y && c + d != x)) flag = true;
        // cout << a << " " << b << endl;

        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
	}
	return 0;
}
