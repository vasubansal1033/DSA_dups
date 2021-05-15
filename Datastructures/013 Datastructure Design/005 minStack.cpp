class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> mini;

    MinStack() {

    }

    void push(int x) {

        if(stk.empty()){
            stk.push(x);
            mini.push(x);
            return;
        }

        if(x<=getMin()){
            stk.push(x);
            mini.push(x);
        }else{
            stk.push(x);
        }

    }

    void pop() {

        if(stk.top()!=mini.top())
            stk.pop();
        else{
            stk.pop();
            mini.pop();
        }

    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
