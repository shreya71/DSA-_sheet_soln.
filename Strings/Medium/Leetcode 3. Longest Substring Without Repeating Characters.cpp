/****************************************************************************************************************************************************
QUESTION: Given a string s, find the length of the longest substring without repeating characters.

APPROACH: Sliding Window Approach used.
          A vector bool is created to keep record of 256 chars whether visited or not, Two loops run accordingly.
*****************************************************************************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxn = 0;
        for(int i = 0; i < s.size(); i++)             // keeps track of start of substring
        {
            vector<bool> visited(256) ;
            for(int j = i; j < s.size(); j++)         // increments till repeated chars not encountered
            {
                if(visited[s[j]] == true)             // if repeated break
                    break;
                else
                {
                    maxn = max(maxn, j-i+1);
                    visited[s[j]] = true;
                }
            }
            visited[s[i]] = false;                    // since we leave the substring we make its chars as unvisited
        }
        return maxn;
    }
};
