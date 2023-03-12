#include "iostream"
using namespace std;
#include "vector"

bool CP(vector<int>& nums, int ind, int lsum, int rsum, vector<vector<int>> &dp,vector<int> &larry, vector<int> &rarry)
{
    // base
    if(lsum == rsum) return true;
    if(ind == nums.size() || rsum == 0) return false;
    
    if(dp[ind][rsum] != -1) return dp[ind][rsum];
    
    // take
    larry.push_back(nums[ind]);
    int a = CP(nums, ind + 1, lsum + nums[ind], rsum - nums[ind], dp, larry, rarry);
    if(a) return a;
    // don't --- means store in the right!!!!
    larry.pop_back();
    rarry.push_back(nums[ind]);
    int b = CP(nums, ind + 1, lsum, rsum, dp, larry, rarry);
    if(!b) rarry.pop_back();
    // see the 1st 2 levels. atlest one of them should return true...
    return dp[ind][rsum] = a|| b;
}

bool canPartition(vector<int>& nums, vector<int> &larry, vector<int> &rarry) {
    int rsum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        rsum += nums[i];
        //rarry.push_back(nums[i]);
    }
    
    // I don't rem why we took + 1 & nums.size as size of vec properly... Just checkout properly later.
    vector<vector<int>> dp(nums.size() + 1, vector<int> (rsum + 1, -1));
    
    return CP(nums, 0, 0, rsum, dp, larry, rarry);
}

int main()
{
    vector<int> nums = {1,5,11,5}, larry, rarry;
    if(canPartition(nums, larry, rarry))
    {
        for (int i = 0; i < larry.size(); i++)
        {
            cout << larry[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < rarry.size(); i++)
        {
            cout << rarry[i] << " ";
        }        
    }
    else
    {
        cout << -1;
    }

    return 0;
}