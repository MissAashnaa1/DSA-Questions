class MinStack {
    stack<pair<long long,long long>>s;
public:
    MinStack() {
        
    }
    //-2147483647
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }
        else if(s.top().second<val){
            s.push({val,s.top().second});
        }
        else {s.push({val,val});
        }
            }
    
    void pop() {
        if(s.size()==0){
            return;
        }
        s.pop();
    }
    
    int top() {
        if(!s.size()){
            return -1;
        }
        return s.top().first;
    }
    
    int getMin() {
         if(!s.size()){
            return -1;
        }
        return s.top().second;
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