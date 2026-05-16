class MinStack {
        stack<pair<int,int>> s;
        int minimum;
public:
    MinStack() {
        minimum = INT_MAX;
    }
    
    void push(int val) {
        minimum = min(minimum, val);
        s.push({val, minimum});
    }
    
    void pop() {
        s.pop();
        if(!s.empty()){
            minimum = s.top().second;
        } else {
            minimum = INT_MAX;
        }

    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
