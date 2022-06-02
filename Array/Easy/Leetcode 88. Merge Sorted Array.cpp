/*********************************************************************************************************************************

QUESTION: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing
          the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order.
          The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this,
          nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0
          and should be ignored. nums2 has a length of n.
          
APPROACH: Merge Sort algorithm used. (explianed in comments)          

************************************************************************************************************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j =0, k = 0;
        vector<int> temp = nums1;                      // nums1 stored in temp vector
        while(i < m && j < n )                        // minimum of the two elements stored till either n1 or n2 reached
        {
            if(temp[i] > nums2[j] )
            {
                nums1[k] = nums2[j];
                j++; k++;
            }
            else
            {
                nums1[k] = temp[i];
                i++; k++;
            }
        }
        while( i < m)                   // loop to store left out values of temp, i.e., nums1
        {
            nums1[k] = temp[i];
                i++; k++;
        }
        while(j < n)                   // loop to store left out values of nums2
        {
             nums1[k] = nums2[j];
                j++; k++;
        }
    }
};
