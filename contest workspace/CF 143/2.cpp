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
	    int n, k;
		cin >> n >> k;
		int firstflag = 0, secondflag = 0;
		while (n--)
		{
			int a, b;
			cin >> a >> b;
			if(a == k) firstflag = 1;
			if(b == k) secondflag = 1;
		}

		if(firstflag && secondflag) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	return 0;
}
