class MyQueue {
public:
    stack<int>temp;
    MyQueue() {
        
    }
    
    void push(int x) 
    {
        temp.push(x);
    }
    
    int pop() 
    {
        vector<int>tp;
        while(!temp.empty())
        {
            tp.push_back(temp.top());
            temp.pop();
        }
        int ans=tp.back();
        tp.pop_back();
        for(int i=tp.size()-1;i>=0;i--)
        {
            temp.push(tp[i]);
        }
        return ans;
    }
    
    int peek() 
    {
        vector<int>tp;
        while(!temp.empty())
        {
            tp.push_back(temp.top());
            temp.pop();
        }
        int ans=tp.back();
        // tp.pop_back();
        for(int i=tp.size()-1;i>=0;i--)
        {
            temp.push(tp[i]);
        }
        return ans;
    }
    
    bool empty() {
        return temp.empty();
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