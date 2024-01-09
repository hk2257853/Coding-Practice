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
        int n, k;
        cin >> n >> k;

        for (int i = n; i > k+1; i--)
        {
            cout << i << " ";
        }
        for (int i = 1; i <= k+1; i++)
        {
            cout << i << " ";
        }cout << endl;
        
        
	}
	return 0;
}
