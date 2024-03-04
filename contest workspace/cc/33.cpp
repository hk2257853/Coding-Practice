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
        vector<int> vec;
        int size, x, size2;
        cin >> size >> size2;
        while (size)
        {
            size--;
            cin >> x;
            vec.push_back(x);
        }


        int maxnum = 0;
        while (size2--)
        {
            cin >> x;
            maxnum = max(maxnum, x);
        }

        // eg: 5 7 12 11 13 10
        // sum = 3
        // 5 7 12 10 11 13 
        // last 3 got sorted
        if(maxnum > vec.size()) maxnum = vec.size();
        sort(vec.end() - maxnum, vec.end());        
        
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }cout << endl;
        

        
    }
    return 0;
}
