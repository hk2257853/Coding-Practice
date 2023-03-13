// This is a very interesting obs/math based prob I had done b4. 
// Logic on notebook

// Commented code is better.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int j = 0, profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - prices[j] > 0) profit = max(profit, prices[i] - prices[j]);
            else j = i;
        }
        return profit;
    }
};

/*
Re wrote the code:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - minprice > ans) ans = prices[i] - minprice;
            if(prices[i] < minprice) minprice = prices[i];
        }
        return ans;
    }
};
This one is more obvious to me compared to the one I wrote above...
LOGIC: 
max - min = maxprofit

so keep one variable to keep track of min
one just traverses n checks does max - min
if min < cur, min = cur

*/