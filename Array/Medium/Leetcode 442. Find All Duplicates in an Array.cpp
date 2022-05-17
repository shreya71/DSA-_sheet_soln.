/****************************************************************************************************************
QUESTION: Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice,
          return an array of all the integers that appears twice. You must write an algorithm that runs in O(n) time and uses only constant extra space.
 
APPROACH: Using maps to store key value and its count, we want the array of integers that occur more than once (i.e. count>1)
******************************************************************************************************************/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         int n = nums.size();
        map<int, int> m ;
        for(int i = 0; i< n; i++)
        {
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto it: m)
        {
            if(it.second > 1)
            v.push_back(it.first);
        }
        return v;        
    }
};
