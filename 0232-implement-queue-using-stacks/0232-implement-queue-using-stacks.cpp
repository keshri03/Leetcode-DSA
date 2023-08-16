class MyQueue {
public:
    stack<int>main,copy;
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
        
    }
    
    int pop() {
        int ans;
        while(!main.empty()){
            copy.push(main.top());
            main.pop();
        }
        ans=copy.top();
        copy.pop();
        while(!copy.empty()){
            main.push(copy.top());
            copy.pop();
        }
        return ans;

        
    }
    
    int peek() {
        int ans;
         while(!main.empty()){
            copy.push(main.top());
            main.pop();
        }
        ans=copy.top();
        while(!copy.empty()){
            main.push(copy.top());
            copy.pop();
        }
        return ans;
        
    }
    
    bool empty() {
        if(main.size()==0) return true;
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