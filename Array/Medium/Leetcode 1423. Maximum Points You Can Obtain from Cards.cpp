/**********************************************************************************************************************************************
QUESTION: There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
          In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards. Your score is the sum of the
          points of the cards you have taken. Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
          
APPROACH: Taking sum of required number of(k) consecutive terms from beginning, then checking all possibilities for max sum by removing k-1th term from sum and
          adding last term of the array/vector. Repeat the process till sum of all k consecutive terms starting from left is obtained. Update sum wherever max obtained.
          
************************************************************************************************************************************************/  

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0, s =0;
        int l = n-1;
        for(int i = 0; i<k ;i++)
        {
           sum += cardPoints[s];
            s++;
        }
        s -= 1;
        int temp = sum;
        for(int i =0; i<k; i++)
        {
            temp += cardPoints[l] - cardPoints[s] ;
            if(temp > sum )
            {
                sum = temp;
            }
            s--; l--;
        }
        return sum;
    }
};
