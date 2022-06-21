class MyQueue {
public:
    stack<int> s1;
        stack<int> s2;
    MyQueue() {
    }
        
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty() && s2.empty())
        {
            cout << "null" << endl;
            return -1;
        }
        if(s2.empty())
        {
        while(!s1.empty())
        {
            s2.push(s1.top());
                s1.pop();
        }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
        
    }
    
    int peek() {
            if(s1.empty() && s2.empty())
        {
            cout << "null" << endl;
            return -1;
        }
        if(s2.empty())
        {
        while(!s1.empty())
        {
            s2.push(s1.top());
                s1.pop();
        }
        }
        int topval = s2.top();
        return topval;
        
    }
    
    bool empty() {
         if(s1.empty() && s2.empty())
        return 1;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
