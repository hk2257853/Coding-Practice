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
	    int size;
        string s;
        cin >> size >> s;

        int count1 = 0 , count0 = 0;
        for(int i = 0; i < size; i++)
        {
            if(s[i] == '1')
            {
                count1++;
            }
            else count0++;
        }
        int op = 0;
        if(count1 > count0) 
        {
            op++;
            op += count0;
        }
        else op += count1;
        cout << op << endl;
        

	}
	return 0;
}
