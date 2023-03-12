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
        int na, nb;
        cin >> na >> nb;
	    string a, b;
        cin >> a >> b;
        int count = 0;
        for (int i = 0; i < na - 1; i++)
        {
            if(a[i] == a[i + 1]) count++;
        }

        if(a[na - 1] == b[nb - 1]) count++;
        
        for (int i = 0; i < nb; i++)
        {
            if(b[i] == b[i + 1]) count++;
        }

        if(count <= 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        

	}
	return 0;
}
