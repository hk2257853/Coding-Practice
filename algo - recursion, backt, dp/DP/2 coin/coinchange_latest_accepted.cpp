// there's a capacity n repetition is allowed. its unbounded knap

// 90% on my own this time!
// 1st needed to identify the type n then it was on my coding n debugging skills (I need to know what's actually happening rather than blindly following the template)

#include "iostream"
using namespace std;
#include "vector"
#include "limits.h"

int mincoins(vector<int> &vec, int n, int sum, vector<int> &dp)
{
    // base
    if(sum == 0) return 0;
    
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(dp[sum] != -1) return dp[sum];
        int subans = INT_MAX; // can't make this INT_MAX!
        if(sum - vec[i] >= 0)
        subans = /*1 +*/ mincoins(vec, n, sum - vec[i], dp);

        if(subans != INT_MAX) subans++; // by not adding in the above line n putting this check solved the overflow issue!
        ans = min(ans, subans); // int case of 7 & 9 as input for sum = 2 it returns INT_MAX
    }
    return dp[sum] = ans;    
}

// sum is the only changing variable (see what I am changing in function call only)

int main()
{
    vector<int> vec = {7};
    int sum = 9;
    vector<int> dp(sum + 1, -1); // table size will be +1 as I have 0 index/sum too! (apart from 1 to 11)
    //dp[0] = 0;
    int ans = mincoins(vec, vec.size(), sum, dp);    
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

// leetcode accepted!!!!!!