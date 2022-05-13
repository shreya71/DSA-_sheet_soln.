/*****************************************************************************************
#############################################IMPORTANT################################# 
Significance of vector<int>&
                pass by reference, modifying and returning values of the vector nums
####################################################################3#################

QUESTION: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums.
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

APPROACH: Keys along with its occurences count stored in map and then each key of the map stored once in a temporary vector v.
          temp values stored back to num and rest of them left empty. clear value of temp vector to reduce runtime......space reduce krne ke liye should think of a new approach.
          


***********************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m ;
        for(int i = 0; i< n; i++)
        {
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto it: m)
        {
            v.push_back(it.first);
        }
        int k = v.size();
        for(int i = 0; i<k; i++)
        {
            nums[i] = v[i];
        }
        v.clear();
        return k;
    }
};
