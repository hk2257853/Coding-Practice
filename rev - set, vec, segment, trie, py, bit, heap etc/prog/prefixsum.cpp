#include "iostream"
using namespace std;
#include "vector"

// lol can't believe having trouble in printing subarrays!

int main()
{
    int n;
    cin >> n;
    vector<int> vec, prefixsum;

    for (int i = 1; i <= n; i++)
    {
        vec.push_back(i);
    }

    prefixsum.push_back(vec[0]);
    for (int i = 1; i < n; i++)
    {
        prefixsum.push_back(vec[i] + prefixsum[i - 1]);
    }

    // output
    for (int i = 0; i < n; i++)
    {
        cout << prefixsum[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // prefix sum eliminates the need to traverse from i to j
            int sum;
            if (i > 0)
                sum = prefixsum[j] - prefixsum[i - 1]; // this is like using geometry
            else
                sum = prefixsum[j];

            cout << sum << endl;
        }
    }
    // Note: my focus here was to eliminate k loop, ie I coded down to up

    // same ans as I did in subarray! good work boi!!
}

// time complexity: O(n2)
