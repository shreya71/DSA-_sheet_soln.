/**********************************************************************************************************************
QUESTION: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
          You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
        
APPROACH: As x+y = target so we search target - x in the vector nums and if found we store the indices of x and found vector in the vector and return .

*********************************************************************************************************************/

//Time Complexity: O(N^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        int n = nums.size(), t = 0;  
        for(int i = 0; i< n ; i++)
        {
            int k = target - nums[t];
            if(i != t && nums[i] == k)
            {
                index.push_back(t);
                index.push_back(i);
                i = n;
            }
            if(i == n-1)
            {
                i = -1;
                t++;
            }
        }
        return index;
    }
};


//*****************************************************************************************************************************************************8
// Time Complexity: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> v;
        map<int, int> m;
        for(int i = 0; i< nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end())
            {
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                break;
            }
            m[nums[i]] = i ;
        }
        return v;
    }
};
