/******************************************************************************************************************************
QUESTION: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.A subarray is a
          contiguous non-empty sequence of elements within an array.
          
APPROACH: We take the sum of all elemnets before index i and check whether it is equal to target or not.
          secondly we check whether sum-target is present or not.......if yes we add the count of sum-target
          we have created a map storing the prefix sum as key and its occurences as its value.

**********************************************************************************************************************************/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int sum = 0, count = 0;
    map<int, int> m;
    for(int i = 0; i< nums.size() ; i++)
    {
        sum += nums[i];
        if(sum == k)
        count++;
        if(m.find(sum-k) != m.end())
        count += m[sum-k] ;
        m[sum]++;
    }
    return count;
    }
};
