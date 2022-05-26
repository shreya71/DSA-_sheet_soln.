/**************************************************************************************************************************************
QUESTION: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:1. 0 <= a, b, c, d < n
                                                                                                                  2. a, b, c, and d are distinct.
                                                                                                                  3. nums[a] + nums[b] + nums[c] + nums[d] == target
          You may return the answer in any order.
          
APPROACH: Same as 3 sum problem.
****************************************************************************************************************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        if(n < 4)
            return {} ;
        for(int i = 0; i <n-3; i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
            for(int j = i+1; j <n-2; j++)
            {
                 if(j == i+1 || nums[j] != nums[j-1])
                 {
                    int k = j+1, l=n-1;
            while(k<l)
        {
                int sum = nums[i]+nums[j];
            if(sum == target - nums[k]-nums[l] )
            { 
                v.push_back({nums[i], nums[j], nums[k], nums[l]});
                while(k<l && nums[k] == nums[k+1])k++;
                while(k<l && nums[l] == nums[l-1])l--;
                l--; k++;
            }
            else if(nums[i]+nums[j] > target-nums[k]-nums[l])
                l--;
            else k++;
        } 
                 }
            }
            }
        }
        return v;
    }
};
