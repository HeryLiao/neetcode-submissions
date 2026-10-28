class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
    void inToOut(){
        if (st2.empty()){
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        inToOut();
        int v = st2.top();
        st2.pop();
        return v;
    }
    
    int peek() {
        inToOut();
        return st2.top();
    }
    
    bool empty() {
        return st1.size() == 0 && st2.size() == 0 ;
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