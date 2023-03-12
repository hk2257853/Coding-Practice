#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

/*
The above approach may not work for all denominations. For example, it doesn’t work for denominations {9, 6, 5, 1} and V = 11. The above approach would print 9, 1 and 1. But we can use 2 denominations 5 and 6. 
For general input, below dynamic programming approach can be used: 
*/
// then why tf doing this?

/*
The denominations are of Indian Currency, which is designed in such a way that adding two smaller 
denominations will not be greater than a bigger denomination
*/

int coinChange(vector<int>& coins, int amount) 
{
    sort(coins.begin(), coins.end());
    int ans = 0;
    for(int i = coins.size() - 1; i >= 0; i--)
    {
        while(coins[i] <= amount)
        {
            amount = amount - coins[i];
            ans++;
        }
    }
    
    if(amount > 0) return -1;
    
    return ans;
}

int main()
{
    vector<int> deno = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
            
    cout << coinChange(deno, 93) << endl;

    for(int i = 10; i > 0; i--)
    { // 1st part is initialization
    // till condition is true
    // 1st this code will run n then the i-- part
        cout << i << " ";
    }
}