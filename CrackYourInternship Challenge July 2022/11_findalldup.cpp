// I used a hash map n did...

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> uset;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(uset.find(nums[i]) != uset.end()) ans.push_back(nums[i]);
            else uset.insert(nums[i]);
        }
        
        return ans;
    }
};