#include "iostream"
using namespace std;
#include "vector"
#include "limits.h"

// leetcode accepted soln below

int lis(vector<int> &vec, int ind, int prevind, vector<vector<int>> &dp)
{
    if(ind >= vec.size()) return 0;
    if(dp[ind][prevind] != -1) return dp[ind][prevind];
    int take = 0;
    // take
    if(vec[ind] > vec[prevind])
    take = 1 + lis(vec, ind + 1, ind, dp);

    int dtake = lis(vec, ind + 1, prevind, dp); // the main mistake was here! wrote ind inplace of prevind!

    return dp[ind][prevind] = max(take, dtake);
}
// this won't work eg 1 2
//                    p i
// my code will assign ans = 1 
// basically I processed 1st 2 indices in a wrong way...
int main()
{
    vector<int> vec = {2, 1};
    vec = {0,1,0,3,2,3};
    //vec = {7,7,7,7,7,7,7};
    vector<vector<int>> dp(vec.size() + 1, vector<int>(vec.size() + 1, -1)); // doing + 1 in size gave the ans 
    // If the size is 4, prev can go from 0 to 3?
    cout << lis(vec, 1, 0, dp);
    
    return 0;
}

/*
// Accepted soln
// 70% on my own, will retry!
class Solution {
public:
    int lis(vector<int> &vec, int ind, int prevind, vector<vector<int>> &dp)
    {
        if(ind == vec.size()) return 0; // ind is in front of prev! so check for ind not prev!
        if(prevind != -1 && dp[prevind][ind] != -1) return dp[prevind][ind];
        int take = 0;
        // take
        if(prevind == -1 || vec[ind] > vec[prevind])
        take = 1 + lis(vec, ind + 1, ind, dp);

        int dtake = lis(vec, ind + 1, prevind, dp);

        if(prevind == -1) return max(take, dtake);
        return dp[prevind][ind] = max(take, dtake);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1)); // doing + 1 in size gave the ans 
    // If the size is 4, prev can go from 0 to 3?
        return  lis(nums, 0, -1, dp);
    }
};
*/