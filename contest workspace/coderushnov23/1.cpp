#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

int main()
{
	int t;
	// cin >> t;
	// while (t)
	// {
		t--;
        int n;
        string s;
        cin >> n >> s;

        int x = 0, y = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'L') x--;
            if(s[i] == 'R') x++;
            if(s[i] == 'D') y--;
            if(s[i] == 'U') y++;
        }
        cout << x << " " << y << endl;        
	// }
	return 0;
}
