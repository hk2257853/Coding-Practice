// hashmap method's too simple.
// 2 pointers logic isn't that obvious... but the method will be good in toolkit.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nomap;
        vector<int> ansvec;
        for(int i  = 0; i < nums.size(); i++)
        {
            if(nomap.find(target - nums[i]) != nomap.end())
            {
                ansvec.push_back(abs(nomap[target - nums[i]]));
                ansvec.push_back(i);
                break;
            }
            
            nomap[nums[i]] = i;
        }
        return ansvec;
    }
};