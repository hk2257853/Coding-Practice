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
        ll n;
        cin >> n;
        
		if (n < 7 || n == 9)
		{
			cout << "NO" << endl;
		}
		else if(n % 3 == 1 || n % 3 == 2) // not div by 3 case
		{
			cout << "YES" << endl;
			cout << 1 << " " << 2 << " " << n - 3 << endl;			
		}
		else
		{
			cout << "YES" << endl;
			cout << 1 << " " << 4 << " " << n - 5 << endl;			
		}
	}
	return 0;
}
