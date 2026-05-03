class MinStack {
public:
    stack<int> S;
    stack<int> minS;
    MinStack() {
    }
    
    void push(int val) {
        S.push(val);
        int temp = min(val , minS.empty() ? val : minS.top());
       minS.push(temp);
    }
    
    void pop() {
        S.pop();
        minS.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
