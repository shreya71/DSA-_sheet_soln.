/****************************************************************************************************************
QUESTION: You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide
          to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
          Find and return the maximum profit you can achieve.
          
 APPROACH: for every (i+1)th term greater than ith day price we see a profit. (*if only one day data given no profit or loss can happen)
 
 ****************************************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), sum = 0;
        if(n==1)
            return 0;
        for(int i =0; i<n-1; i++)
        {
           if(prices[i]<prices[i+1])
            {
                sum  = sum + prices[i+1] - prices[i];
            }
        }
        return sum;
    }
};
