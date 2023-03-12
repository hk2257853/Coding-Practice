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
        int n;
        cin >> n;
        vector<int> ans;

        for (int i = 1; i <= n/2; i++)
        {
            ans.push_back(i);    
        }
        
        for (int i = n; i > n/2; i--)
        {
            ans.push_back(i);
        }

        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        

	    
	}
	return 0;
}
