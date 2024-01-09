#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

void fillPrefixSum(vector<int> &vec, vector<int> &prefixSum)
{
    prefixSum.push_back(vec[0]);
    for (int i = 1; i < vec.size(); i++)
        prefixSum.push_back(prefixSum[i - 1] + vec[i]);
}

int main()
{
    int t;
    cin >> t;
    while (t)
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

        vector<int> prefixSumOdd, prefixSumEven;

        for (int i = 0; i < vec.size(); i++)
        {
            if (i % 2 == 0)
            {
                prefixSumEven.push_back(vec[i]);
            }
            else
            {
                prefixSumOdd.push_back(vec[i]);
            }
        }

        for (int i = 1; i < prefixSumEven.size(); i++)
        {
            prefixSumEven[i] += prefixSumEven[i - 1];
        }
        for (int i = 1; i < prefixSumOdd.size(); i++)
        {
            prefixSumOdd[i] += prefixSumOdd[i - 1];
        }
        vector<int> prefixSum;
        fillPrefixSum(vec, prefixSum);

        // print 
        for(int i = 0; i < prefixSumEven.size(); i++)
        {
            cout << prefixSumEven[i] << " ";
        }

        cout << endl;

        for(int i = 0; i < prefixSumOdd.size(); i++)
        {
            cout << prefixSumOdd[i] << " ";
        }

        // print prefixSum
        cout << endl;
        for(int i = 0; i < prefixSum.size(); i++)
        {
            cout << prefixSum[i] << " ";
        }

        cout << endl;cout << endl;
        
    }
    return 0;
}
