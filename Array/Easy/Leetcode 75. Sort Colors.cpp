/************************************************************************************************************
QUESTION: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
          with the colors in the order red, white, and blue.
          We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
          You must solve this problem without using the library's sort function.

APPROACH: Bubble sort technique used
          Runtime error using insertion sort, stackoverflow
***************************************************************************************************************/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int counter = 1;
   while(counter < n)
   {
   for(int i = 0; i<n-counter; i++)
   {
           if(nums[i] > nums[i+1])
           {
               int temp = nums[i+1];
               nums[i+1] = nums[i]; 
               nums[i] = temp;
           }
   }
   counter++;
   }
        cout << "[" ;
   for(int i = 0; i< n ; i++)
   {
       cout<< nums[i] << " ";
   }
       cout << "]" << endl; 
    }
};
