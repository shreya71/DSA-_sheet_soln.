/****************************************************************************************************************************************
QUESTION: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump 
          length at that position. Return true if you can reach the last index, or false otherwise.
          
APPROACH: We can reach the end even if we make a jump of 1 step at every index but if max jump is 0 at any index except the last index then a condition to jump over
          0 by previous elements. (* Solve min jump question)   (#Shorter code)
          
******************************************************************************************************************************************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), end = 1;
        if(n==1)
            return true;
        for(int i = 0; i< n; i++)
        {
            if(nums[i] == 0)
            {
            if(i == 0)
                return false;
                if(i == n-1)
                    return true;
                for(int j = i-1; j>= 0; j--)
                {
                    if(nums[j] >= i+1-j)
                    {
                        end = 1;
                        j = -1;
                    }
                else end = 0;
                }
                if(end == 0)
                    return false;
            }
        }
            return true;
    }
};


// ###################################################                   SHORTER CODE WITH MOST VOTES              ##############################################


