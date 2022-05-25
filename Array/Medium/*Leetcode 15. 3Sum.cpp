/**********************************************************************************************************************************
QUESTION: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
          Notice that the solution set must not contain duplicate triplets.

APPROACH: (Combined approach of 2 sum part 1 and 2 used.) k is fixed such that for i>0 element at k != k-1 to avoid repetitions. After getting sum = 0 we also check
          i+1 != i and j-1 != j.....conditions applied accordingly to avoid any sort of repetitions, rest conditions are same as two sum part 2 problrm.

************************************************************************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        if(n < 3)
            return {} ;
        for(int k = 0; k<n-2; k++)
        {
            if(k == 0 || nums[k] != nums[k-1])
            {
            int i = k+1, j = n-1;
            while(i<j)
        {
            if(nums[i]+nums[j]+nums[k] == 0 )
            { 
                v.push_back({nums[i], nums[j], nums[k]});
                while(i<j && nums[i] == nums[i+1])i++;
                while(i<j && nums[j] == nums[j-1])j--;
                j--; i++;
            }
            else if(nums[i]+nums[j]+nums[k] > 0)
                j--;
            else i++;
        }
        }
        }
        return v;
    }
};
