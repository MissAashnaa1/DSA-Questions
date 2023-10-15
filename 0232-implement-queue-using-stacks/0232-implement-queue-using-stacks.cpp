class MyQueue {
    stack<int>s;
public:
    MyQueue() {
        

    }
    
    void push(int x) {
        if(s.size()==0){
            s.push(x);
            return;
        }
        int ele=s.top();
        s.pop();
        push(x);
        s.push(ele);
       
    }

    // Push the new element onto the original stack
  

    // Move the elements back from the temporary stack to the original stacp
    
    
    int pop() {
        if(s.empty()){
            return -1;
        }
        int ele=s.top();
        s.pop();
        return ele;
    }
    
    int peek() {
        if(s.empty()){
            return -1;
        }
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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