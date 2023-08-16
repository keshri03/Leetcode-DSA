class MyStack {
public:
    queue<int>main,copy;
    MyStack() {
        
    }
    
    void push(int x) {
        main.push(x);
        
    }
    
    int pop() {
        int ans;
        while(!main.empty()){
            
            if(main.size()==1){
                ans=main.front();
                main.pop();
                continue;
            }
            copy.push(main.front());
            main.pop();
        }
         while(!copy.empty()){
            main.push(copy.front());          
            copy.pop();
        }
        return ans;
        
        
    }
    
    int top() {
        int ans;
        while(!main.empty()){
            copy.push(main.front());
            if(main.size()==1) ans=main.front();
            main.pop();
        }
         while(!copy.empty()){
            main.push(copy.front());          
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
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */