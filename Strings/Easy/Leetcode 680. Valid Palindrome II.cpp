/**********************************************************************************************************************************************************
QUESTION: Given a string s, return true if the s can be palindrome after deleting at most one character from it.

APPROACH: Two pointers are used from both ends and chars are compared a function Check() made to see whether skipping a letter from either side the palindrome 
          property is maintained or not and ans. returned. Time Complexity: O(N)
          (Take care of NOTE, when to use increment/decrement operators n when not to use it)
************************************************************************************************************************************************************/          

class Solution {
public:
    bool Check(string s, int i, int j)
    {
        while(i < j )
        {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j =s.length()-1;
        while(i < j )
        {
            if(s[i] != s[j])
               return (Check(s, i+1, j) || Check(s, i, j-1)) ;             // NOTE: *Don't use increment or decrement operator here
           i++, j-- ;
        }
            return true;
    }
};
