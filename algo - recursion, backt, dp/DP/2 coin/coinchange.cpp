#include "iostream"
using namespace std;
#include <climits>

int minCoins(int arr[], int n, int arrsize)
{
    // base
    if(n == 0) return 0;

    // int arrsize = sizeof(arr) / sizeof(arr[0]); // Doing here doesn't work for some reason
    // cout << arrsize << " ";                      // Can be cause its a arr[] is a reference 
        
    //int ans = arr[0]; // he took INT_MAX
    int ans = INT_MAX;
    // this is literally coding the recursion tree (but looking at only 0th & 1st level)
    for (int i = 0; i < arrsize; i++) // Applying on each...
    {
        if(n - arr[i] >= 0)
        {
            int subans = minCoins(arr, n - arr[i], arrsize);
            if(subans != INT_MAX && subans + 1 < ans) ans = subans + 1; // 19:13
            // min(subans + 1, ans)
        }
    }
    return ans;   
}

int main()
{
    int arr[] = {2, 3, 1};
    int n = 18;
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    cout << minCoins(arr, n, arrsize);

    return 0;
}