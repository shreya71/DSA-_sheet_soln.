/*****************************************************************************************************************************************************
QUESTION: Given an input string s, reverse the order of the words.A word is defined as a sequence of non-space characters. The words in s will be separated
          by at least one space.Return a string of the words in reverse order concatenated by a single space. Note that s may contain leading or trailing
          spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
          
APPROACH: 1. To store each word in a string vector and append in reverse order to empty string.
             Time Complexity = O(N)
             Space Complexity = O(N)
             
          2. First we reverse the entire string then we reverse each word one by one and put spaces as per requiremnet.
             Time Complexity = O(N)
             Space Complexity = O(1)

*******************************************************************************************************************************************************************/

// 1.
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string s1 = "";
        for(int i = 0; i< s.length(); i++)
        {
            if(s[i] != ' ')
                s1 += s[i] ;
            else
            {
                if(s1 != "")
                v.push_back(s1) ;
                s1 = "" ;
            }
        }
        if(s[s.length()-1] != ' ')
            v.push_back(s1) ;
        int n = v.size() ;
        s1 = v[n-1];
        for(int i = n-2; i >= 0; i--)
            {s1 += " " ;
            s1.append(v[i]);}
        return s1;
    }
};

// 2.

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};
