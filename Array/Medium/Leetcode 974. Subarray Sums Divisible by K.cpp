/***********************************************************************************************************
QUESTION: Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
          A subarray is a contiguous part of an array.
          
*************************************************************************************************************/
/*         #####################################need another approach############################      66/73 test cases passed        O(n^2) time complexity   */

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

// ############################################################################################


/***********************************     O(n) Time complexity approach       *************************************/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         int sum = 0, count = 0, n = nums.size();
    map<int, int> m;
        m[0]++ ;                            // intially storing sum as 0(required) so as to not miss the basic subarray
        for(int i = 0; i< n ; i++)
        {
             sum += nums[i];
            if(sum%k >= 0)       
                nums[i] = sum%k;
            else
                nums[i]  =sum%k + k;
        }
        
        for(int i = 0 ; i< n; i++)
        {
            m[nums[i]]++;
        }
    for(auto it : m)
    {
        if(it.second > 1 )
        {
            count += it.second * (it.second - 1)/2;
        }
    }
        return count;
    }
};
