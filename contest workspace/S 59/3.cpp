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
	    vector<int> vec;
        int size, x;
        cin >> size;
        while (size)
        {
            size--;
            cin >> x;
            vec.push_back(x);
        }
        
        vector<int> vec2;        
        cin >> size;
        while (size)
        {
            size--;
            cin >> x;
            vec2.push_back(x);
        }

        ll maxans = 0, sum = 0;
        for (int i = 0; i < vec.size(); i++)
        {            
            sum += vec[i];
            maxans = max(sum, maxans);
        }
        
        sum = 0;
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            sum += vec[i];
            maxans = max(sum, maxans);
        }

        for (int i = 0; i < vec2.size(); i++)
        {
            if(vec2[i] > 0) maxans += vec2[i];
        }
        
        cout << maxans << endl;

	}
	return 0;
}
