/******************************************************************************************************************************
QOESTION: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:
          1. Open brackets must be closed by the same type of brackets.
          2. Open brackets must be closed in the correct order.
          
APPROACH: STACK concept used.

******************************************************************************************************************************/

class Solution {
public:
    bool isValid(string s) {
         stack<char> s1;  
        for(auto i:s)  
        {
            if(i=='(' or i=='{' or i=='[') s1.push(i);  
            else  
            {
                if(s1.empty() or (s1.top()=='(' and i!=')') or (s1.top()=='{' and i!='}') or (s1.top()=='[' and i!=']')) return false;
                s1.pop();  
            }
        }
        return s1.empty(); 
    }
};
