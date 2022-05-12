/****************
Bubble sort technique used
Runtime error using insertion sort, stackoverflow
*****************/

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
