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
	    string s, T;
        int n;

        cin >> n >> s;

        int a = 0, b = s.size() - 1;
        int i = 0;
        while (i < s.size())
        {
            if(i % 2 == 0) // A's turn. this check wasn't req!!
            {
                if(s[a]== '0') 
                T = '0' + T;
                else
                T.push_back('1');
                a++;
            }
            else
            {
                if(s[b] == '0') 
                T = T + '0';
                else                
                T = '1' + T;                
                b--;
            }
            i++;
        }
        
        cout << T << endl;

	}
	return 0;
}
