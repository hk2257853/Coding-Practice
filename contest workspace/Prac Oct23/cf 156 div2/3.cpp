#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        ll pos;
        cin >> pos;

        int n = s.size();
        // is the following correct?
        int iter = pos / n;
        int curpos = pos - (n + n - iter + 1) * iter / 2;

        priority_queue<pair<char, int>> pq;

        for (int i = 0; i < s.size(); i++)
        {
            pq.push(make_pair(s[i], i));
        }

        // Removing top values
        for (int i = 0; i < iter; i++)
        {
            pq.pop();
        }        

        // put in a vector and sort wrt second element.
        vector<pair<char, int>> v;
        while (!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }


        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        });

        cout << s[curpos];
        
    }

    return 0;
}