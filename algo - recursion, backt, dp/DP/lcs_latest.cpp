#include "iostream"
using namespace std;
#include "vector"

// got accepted only after putting & for the strings in lcs funct!!!

int lcs(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if(ind1 == s1.length() || ind2 == s2.length()) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    int ans = 0, ans2 = 0;
    if(s1[ind1] == s2[ind2])
        ans = 1 + lcs(s1, s2, ind1 + 1, ind2 + 1, dp);
    else
        ans2 = max(lcs(s1, s2, ind1, ind2 + 1, dp), lcs(s1, s2, ind1 + 1, ind2, dp));

    return dp[ind1][ind2] = max(ans, ans2);
}

int main()
{
    string s1 = "abcd", s2 = "bc";
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    cout << lcs(s1, s2, 0, 0, dp);
    return 0;
}