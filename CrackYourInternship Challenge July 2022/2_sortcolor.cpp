// Simply count number of 0s, 1s & 2s
// now put them in nums array
// TC: O(n), SC: O(1)
// This was a simple question I had done long back... I forgot to do count-- back then!

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        vector<int> count(3, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(count[0]) 
            {
                nums[i] = 0;
                count[0]--;
            }
            else if(count[1])
            {
                nums[i] = 1;
                count[1]--;
            }
            else nums[i] = 2;
        }

    }
};