/***********************************************************************************
QUESTION: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
          ##############Note that you must do this in-place without making a copy of the array.##################
          
APPROACH: Iterating from last element finding zeros and swapping with adjacent elements till it reachec the last possible position with a non zero key.

***********************************************************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            for(int i = nums.size()-1; i>=0; i--)
            {
                if(nums[i] == 0)
                {
                    int k = i;
                    for(int j = i+1; j <nums.size(); j++)
                    {
                        if(nums[j] != 0)
                        {
                            int t = nums[k];
                            nums[k] = nums[j];
                            nums[j] = t;
                            k++;
                        }
                        else
                            j++;
                    }
                }
            }
    }
};
