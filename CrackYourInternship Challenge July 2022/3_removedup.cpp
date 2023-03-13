// I used the logic I learned from ques 5
// (If I didn't know that, I would have done in 2 traversals ig)

// I did a silly mistake that took 15 min to debug as I was a bit tired.
// Take rest in between!!

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqsize = 0;     
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[uniqsize] != nums[i]) 
            {
                uniqsize++;
                nums[uniqsize] = nums[i];                
            }
        }
        return uniqsize + 1;
    }
};