#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include<numeric>
using ll = long long;
#include "unordered_set"
bool containsDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();        
    }

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

        int first = vec[0], ind = -1;
        for (int i = 0; i < vec.size(); i++)
        {
            if(first < vec[i])
            {
                ind = i;
                break;
            }    
        }
        
        
        if(ind == -1 || containsDuplicate(vec))
        {
            cout << "-1" << endl;
            continue;
        }

        cout << ind << endl;
        for (int i = 0; i < ind; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;

        cout << vec.size() - ind << endl;
        for (int i = ind; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;

	}
	return 0;
}
