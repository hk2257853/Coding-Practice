//  I wrote a faltu 2 times traversal & O(n) SC soln
// Then checked the discussion and found so good soln!! 
// just put non 0 numbers from start of array (use j to keep track). then just fill up remaining with 0.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0) 
            {
                nums[j] = nums[i];
                j++;
            }
        }            
        
        for(j; j < nums.size(); j++)
        {
            nums[j] = 0;
        }
    }
};