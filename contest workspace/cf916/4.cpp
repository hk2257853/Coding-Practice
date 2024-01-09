#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;

// BIG POSSIBLE MISTAKE: Not using long long!!!!
void findThreeLargestElements(const vector<int> &vec, vector<pair<int, int>> &v)
{
    int n = vec.size();

    // Create a vector of pairs (value, index)
    vector<pair<int, int>> indexedVec;
    for (int i = 0; i < n; i++)
    {
        indexedVec.push_back({vec[i], i});
    }

    // Sort the vector of pairs in ascending order based on values
    sort(indexedVec.begin(), indexedVec.end(), greater<pair<int, int>>());

    // Extract the three largest elements along with their indices
    v.push_back(indexedVec[0]);
    v.push_back(indexedVec[1]);
    v.push_back(indexedVec[2]);
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        t--;
        vector<int> vec1, vec2, vec3;
        int size, x, size2, size3;
        cin >> size;
        size2 = size;
        size3 = size;
        while (size)
        {
            size--;
            cin >> x;
            vec1.push_back(x);
        }

        while (size2)
        {
            size2--;
            cin >> x;
            vec2.push_back(x);
        }

        while (size3)
        {
            size3--;
            cin >> x;
            vec3.push_back(x);
        }

        vector<pair<int, int>> v1, v2, v3;
        // pair<int, int> a1, a2, a3, b1, b2, b3, c1, c2, c3;
        findThreeLargestElements(vec1, v1);
        findThreeLargestElements(vec2, v2);
        findThreeLargestElements(vec3, v3);

        ll ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (v2[j].second == v1[i].second)
                    continue;
                for (int k = 0; k < 3; k++)
                {
                    if (v3[k].second == v2[j].second || v3[k].second == v1[i].second)
                        continue;
                    // if ((ll) v1[i].first + v2[j].first + v3[k].first > ans)
                    //     ans = (ll) v1[i].first + v2[j].first + v3[k].first;
                    ans = max(ans, (ll)(v1[i].first + v2[j].first + v3[k].first));
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

// I could have easily done D that day!
// main time wasting factors: efficiently getting 3 max (as tc is 10^5, sorting is best)
// I wasn't able to write the below algo
// Overall I feel I'll do better next time.
