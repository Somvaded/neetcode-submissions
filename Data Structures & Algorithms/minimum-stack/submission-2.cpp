class MinStack {
        vector<int> v;
        vector<int> minVector;
        int s;
public:
    MinStack() {
        s = -1;
    }
    
    void push(int val) {
        v.push_back(val);
        if(s == -1){
            minVector.push_back(val);
        } else{
            int temp = min(minVector[minVector.size()-1],val);
            minVector.push_back(temp);
        }
        s++;
    }
    
    void pop() {
        if(v.size() == 0){
            return;
        }
        v.pop_back();
        minVector.pop_back();
        s--;
    }
    
    int top() {
        return v[s];
    }
    
    int getMin() {
        return minVector[s];
    }
};
