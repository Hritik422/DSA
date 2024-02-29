class MinStack {
public:
    int arr[100000];
        int to=-1;
        stack<int>s;
        long long mini=1e18;
    MinStack() {
        
    }
    
    void push(int val) {
        to++;
        arr[to]=val;
        if(val<mini)mini=val;
        s.push(mini);
    }
    
    void pop() {
        to--;
        s.pop();
        if(to!=-1)mini=s.top();
        if(to==-1)mini=1e18;
    }
    
    int top() {
        return arr[to];
    }
    
    int getMin() {
        return s.top();
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