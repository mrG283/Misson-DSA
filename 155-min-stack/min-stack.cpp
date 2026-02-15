class MinStack {
public:
    MinStack() {
        
    }
    stack<int>mainstack;
    stack<int>minstack;

    
    void push(int val) {
        mainstack.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }        
        else{minstack.push(min(val,minstack.top()));}
    }
    
    void pop() {
        mainstack.pop();
        minstack.pop();

        
    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */