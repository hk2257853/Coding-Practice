// 2 pointers with i at start & j at end.
// idk when to use this version of 2 pointers.
// most soln r not very intuitive for me... always the question remains: does it covers all test cases?
// here it looks like hit n try rather than a maths proof based (atleast for most video soln)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, maxa=-1;
        
        while(i<j) 
        {
            maxa=max(maxa,min(height[j],height[i])*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxa;
    }
};