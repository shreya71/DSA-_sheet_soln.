/**********************************************************************************************************************************************

QUESTION: Implement strStr(). Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle
          is not part of haystack.
  Clarification: What should we return when needle is an empty string? This is a great question to ask during an interview. For the purpose of this
          problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
          
APPROACH: Finding the substring letter by letter in main string, if at any point the letters don't match pointer is set back to the position where 1st matched letter
          was found and loop is continued.
          
          ########### IMPORTANT  ######################
          KMP ALGORITHM (Knuth Morris Pratt)   USED FOR SEARCHING
          
          
******************************************************************************************************************************************************/

// 1. Simple approach
class Solution {
public:
    int strStr(string haystack, string needle) {
        int count = 0, j =0, index = -1;
        if(needle.size() == 0)
            return 0;
        for(int i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[j])
            {
                count++;
                j++;
            }
            else
            {
                i = i - count;
                count = 0;
                j = 0;
            }
            if(count == needle.size())
            {
                index = i-count+1;
                break;
            }
        }
        return index;
    }
};
