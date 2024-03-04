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
        bool hat = false;
        int count = 0;
        for (int i = 0; i < 6; i++)
        {
            char c;
            cin >> c;
            if(c == 'W') count++;
            else count = 0;
            if(count == 3) hat = true;
        }

        if(hat) cout << "YES" << endl;
        else cout << "NO" << endl;
        
	}
	return 0;
}
