/*********************************************************************************************************************************************************************
QUESTION: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.A subarray
          is a contiguous part of an array.
          
APPROACH: KADANE'S Algorithm
          We carry a subarray sum as long as it gives +ve sum .
************************************************************************************************************************************************************************/

// Time Complexity: O(N)            Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0], sum = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            sum += nums[i];
            if(max < sum)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};
