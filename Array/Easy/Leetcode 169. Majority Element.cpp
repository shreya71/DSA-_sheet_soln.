/****************************************************************************************************************************
QUESTION: Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times.
          You may assume that the majority element always exists in the array.
          
APPROACH: Count of each element stored in hash tables along with it key value and majority element found putting the condition given.

***************************************************************************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int r;
        for(int i = 0; i< nums.size(); i++)
        {
            m[nums[i]]++  ;
        }
        for(auto it: m)
        {
            if(it.second > nums.size()/2)
            r = it.first ;
        }
        return r;
    }
};
