#include "iostream"
using namespace std;
#include <climits>
///////////// In Apna college's he directly used the reccurance relation n got it done.
int minCoins(int arr[], int n, int arrsize, int dp[])
{
    // base
    if(n == 0) return 0;    

    int ans = arr[0]; // he took INT_MAX

    for (int i = 0; i < arrsize; i++) // Applying on each...
    {
        if(n - arr[i] >= 0)
        {
            int subans = 0;
            if(dp[n - arr[i]] != -1)
                subans = dp[n - arr[i]];
            else
                subans = minCoins(arr, n - arr[i], arrsize, dp);

            if(subans != INT_MAX && subans + 1 < ans) ans = subans + 1; // 19:13
        }
    }
    
    dp[n] = ans;
    return ans;   
}

int main()
{
    int arr[] = {7, 5, 1};
    int n = 18;
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = -1;
    dp[0] = 0; // for 0 coins ans is 0

    cout << minCoins(arr, n, arrsize, dp) << endl;

    for (int i = 0; i < n + 1; i++) // 0 to 18... how may coins req for each.
    {
        cout << dp[i] << " ";
    }
    
    return 0;
}