class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>s;
    stack<int>dup;
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(s.size() != 1)
        {
            int temp = s.top();
            s.pop();
            dup.push(temp);
        }
        int ans =  s.top();
        s.pop();
        while(dup.size())
        {
            s.push(dup.top());
            dup.pop();
        }
        return ans;
    }
    
    int peek() {
        while(s.size() != 1)
        {
            int temp = s.top();
            s.pop();
            dup.push(temp);
        }
        int ans = s.top();
        while(dup.size())
        {
            s.push(dup.top());
            dup.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s.size() == 0;
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