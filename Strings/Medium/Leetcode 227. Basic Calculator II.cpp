/******************************************************************************************************************************************************
QUESTION: Given a string s which represents an expression, evaluate this expression and return its value. The integer division should truncate toward zero.
          You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
          Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
          
APPROACH: example:  we have input as, 3+5*2-2/1 so using BODMAS rule we get 11, so we can write the expression as summation of 
                    3 + (5*2) + (-(2/1))
                    n1    n2      n3
                    we can store n1, n2 n n3 in a stack as we proceed in the string and at last we can add all the n's present in the stack.
                    
*********************************************************************************************************************************************************/    

class Solution {
public:
    int calculate(string s) {
        stack<int> s1;
        int n = s.size(), t = 0, sum = 0;
        char sign = '+';                   // for the first number n1 of the expression gets stored in stack as +3           
        for(int i = 0; i < n; i++)
        {
            if(isdigit(s[i]) )
                t = t*10 + (s[i]-'0');
            if(!isdigit(s[i]) && !isspace(s[i]) || i == n-1)
            {
                if(sign == '+')
                    s1.push(t);
                else if(sign == '-')
                    s1.push(-t);
                else
                {
                    int p;
                    if(sign == '*')
                        p = s1.top() * t;
                    else
                        p = s1.top()/t;
                    s1.pop();
                    s1.push(p);
                }
                sign = s[i];                     //the last encountered sign is stored here and then i is incremented
                t = 0;
            } 
        }
        while(!s1.empty())
        {
             sum += s1.top();
            s1.pop();
        }
        return sum;
    }
};
