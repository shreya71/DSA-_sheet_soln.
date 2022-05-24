/**********************************************************************************************************************************************
QUESTION: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). 
          Find two lines that together with the x-axis form a container, such that the container contains the most water.Return the maximum amount of
          water a container can store. Notice that you may not slant the container.

APPROACH: If initial length on left is smaller than initial length on right then we move to the next index of the smaller length, since we needthe max area so we go
          searching for a better length as our index difference will decrease(initially being max)
************************************************************************************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), max = 0, i =0, j = n-1;
        while(i<j)
        {
            int most = (j-i)*(min(height[i], height[j]));
            if(max < most)
                max = most;
            if(height[i] < height[j])
                i++;
            else
                j--; 
        }
        return max;
    }
};
