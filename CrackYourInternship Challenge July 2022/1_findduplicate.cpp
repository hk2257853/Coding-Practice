// I wrote a simple hashset solution
// TC: O(n), SC: O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> usetnum;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if (usetnum.find(nums[i]) != usetnum.end()) 
            {
                ans = nums[i];
                break;
            }
            else usetnum.insert(nums[i]);            
        }
        return ans;
    }
};

// I did try to think of O(1) soln but couldn't find it.
// This soln have 9 approaches
// https://leetcode.com/problems/find-the-duplicate-number/discuss/1892921/Java-9-Approaches-Count-%2B-Hash-%2B-Sort-%2B-Binary-Search-%2B-Bit-%2B-Fast-Slow-Pointers
