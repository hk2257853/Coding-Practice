// took some sample test cases n didn't find any pattern 
// looked for hashmap solution. coulnd't get anything

// so all possibilities is the only way.
// so recursion or iterative? iterative. Its subarray, will be easier to code.
// prefix sum makes it better/easier.

// TC: O(k)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cardsize = cardPoints.size();
        vector<int> prefixsum;
        vector<int> suffixsum;
        prefixsum.push_back(0);
        suffixsum.push_back(0);
        
        for(int i = 0; i < k; i++)
        {
            prefixsum.push_back(prefixsum[i] + cardPoints[i]);
            suffixsum.push_back(suffixsum[i] + cardPoints[cardsize - i - 1]);
        }
        int ans = 0;
        for(int i = 0; i <= k; i++)
        {
            ans = max(ans, prefixsum[i] + suffixsum[k - i]);
        }
        return ans;
    }
};class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cardsize = cardPoints.size();
        vector<int> prefixsum;
        vector<int> suffixsum;
        prefixsum.push_back(0);
        suffixsum.push_back(0);
        
        for(int i = 0; i < k; i++)
        {
            prefixsum.push_back(prefixsum[i] + cardPoints[i]);
            suffixsum.push_back(suffixsum[i] + cardPoints[cardsize - i - 1]);
        }
        int ans = 0;
        for(int i = 0; i <= k; i++)
        {
            ans = max(ans, prefixsum[i] + suffixsum[k - i]);
        }
        return ans;
    }
};class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cardsize = cardPoints.size();
        vector<int> prefixsum;
        vector<int> suffixsum;
        prefixsum.push_back(0);
        suffixsum.push_back(0);
        
        for(int i = 0; i < k; i++)
        {
            prefixsum.push_back(prefixsum[i] + cardPoints[i]);
            suffixsum.push_back(suffixsum[i] + cardPoints[cardsize - i - 1]);
        }
        int ans = 0;
        for(int i = 0; i <= k; i++)
        {
            ans = max(ans, prefixsum[i] + suffixsum[k - i]);
        }
        return ans;
    }
};