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
	    int x, y;
        cin >> x >> y;
        int a = 0, b = 0, c = 0;
        b = y;
        int z = x * 3 - y;
        
        a = z / 2;
        c = z - a;

        // if(z > 100) 
        // {
        //     a = 100 - z;
        //     c = z - a;
        // }
        // else if(z < -100) {
        //     a = 100 + z;
        //     c = z + a;
        // }
        // else
        // {
        //     a = 1;
        //     c = z - a;
        // }


        cout << a << " " << b << " " << c << " " << endl;

	}
	return 0;
}
