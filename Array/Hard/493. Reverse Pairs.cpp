
// 1. Time Complexity = O(N^2)                       TLE for large input cases

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        long long int a[n];
        for(int i =0; i< n; i++)
        a[i] = nums[i];
        for(int i = 0; i< n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(a[i] > a[j]*2 )
                    count++;
            }
        }
        return count;
    }
};
