/*********************************************************************************************
QUESTION: You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing
          a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve
          from this transaction. If you cannot achieve any profit, return 0.
          
APPROACH: if next element is smaller than the current element we upgrade the current element with the next one else we store the difeerence of Next and current and 
          store and go on checking till we get maximum difference satisfying all conditions.
          
**********************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size(), d = 0;
        if(n==1)
            return 0;
         int current = prices[0];
        for(int i = 1; i< n;i++)
        {
            if( prices[i]-current > d)
            {
                d = prices[i]-current;
            }
            else if(current>prices[i])
                current = prices[i];
        }
        return d;
    }
};
