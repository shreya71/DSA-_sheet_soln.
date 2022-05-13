/***************************************************************************************************************
QUESTION: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

APPROACH: using hasmaps, storing the occurence of a particular key along with the key wvalue in map of pair type.
******************************************************************************************************************/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), result;
        map<int, int> hm;
   for(int i =0; i<n; i++)
   {
       hm[nums[i]]++ ;
   }
   for(auto it: hm)
   {
       if(it.second>1)
       result = it.first;
   }
        return result;
    }
};
