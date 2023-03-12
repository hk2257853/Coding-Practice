#include <iostream>
using namespace std;
#include <vector>

// code giving out of bound error on leetcode but working perfectly here...

// I feel more & more comfortable with dp. Once I get hang of it I'll be able to experiment.

int coinChange(vector<int>& coins, int amount) {
    vector<int> table(amount + 1, amount + 1); 
    // if I take -1 min function will always return -1. 
    // if I put INT_MIN, may get overflow? not subtraction anywhere... still safety 1st...

    table[0] = 0; // forgot to write this!!

    for(int i = 0; i < coins.size(); i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            // j - coins[i] is remainder

            table[j] = min(1 + table[j - coins[i]], table[j]);
        }
    }

    if(table[amount] >= amount + 1)  return -1;
    return table[amount];
}

int main()
{
    vector<int> vec = {2};
    cout << coinChange(vec, 0) << endl;
    cout << "hi";
}