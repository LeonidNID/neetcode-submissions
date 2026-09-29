class MinStack {
private:
    stack<int> m_stack;
    stack<int> m_minStack;

public:
    MinStack() = default;
    
    void push(int val) {
        m_stack.push(val);
        m_minStack.empty() ? m_minStack.push(val) : m_minStack.push(min(val, m_minStack.top()));

    }
    
    void pop() {
        m_stack.pop();
        m_minStack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_minStack.top();
    }
};

/*
0 0
2 1
1 1

pop()

2 1
1 1

*/