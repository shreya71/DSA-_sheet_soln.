/***********************************************************************************************************
QUESTION: Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
          A subarray is a contiguous part of an array.
          
*************************************************************************************************************/
/*         #####################################need another approach############################      66/73 test cases passed       */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         int n = nums.size(), count = 0, sum = 0, j =0;
            for(int i = j; i<n; i++)
        {
            sum += nums[i];
            if(sum%k == 0 )
             count++; 
                if( i == n-1 && j < n)
                {
                    sum = 0; 
                    j++;
                    i = j-1;
                }
        }
        return count;
    }
    
};
