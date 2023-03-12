#include "iostream"
using namespace std;
#include "vector"
#include "limits.h"

// coded out smoothly
// main issue logic. Take proper insight so that can identify & solve variations!
// I feel more confident in coding than thinking now lol! gotta work on it too!

int mcm(vector<int> &vec, int s, int e, vector<vector<int>> &dp) 
{
    if(s >= e) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {
        int subans = mcm(vec, s, i, dp) + mcm(vec, i + 1, e, dp) + vec[s - 1] * vec[i] * vec[e];
        ans = min(ans, subans);
    }

    return dp[s][e] = ans;
    
}

int main()
{
    vector<int> vec = {40, 20, 30, 10, 30};
    vector<vector<int>> dp(vec.size(), vector<int>(vec.size(), -1)); // doing +1, not really sure when to do. Adity varma said to always do. I do if I get an out of bound error
    cout << mcm(vec, 1, vec.size() - 1, dp); // didn't do -1
    return 0;
}

// accepted gfg hard!!