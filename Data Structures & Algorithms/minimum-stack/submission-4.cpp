class MinStack {
public:
    std::stack<int> main_stack;
    std::stack<int> min_stack;
    int min;

    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.empty()) {
            min_stack.push(val);
        } else if(val > min_stack.top()) {
            min_stack.push(min_stack.top());
        } else {
            min_stack.push(val);
        }
    }
    
    void pop() {
        int tmp = main_stack.top();
        main_stack.pop();
        min_stack.pop();
        // return tmp;
    }
    
    int top() {
        return main_stack.top();        
    }
    
    int getMin() {
        return min_stack.top();
    }
};