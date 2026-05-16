class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> m = {
            {')','('},
            {'}','{'},
            {']','['}
        };
        for(auto x: s){
            if(x == ')' || x == '}' || x == ']'){ 
                if (st.size() == 0 || st.top() != m[x]){
                    return false;
                }else{
                    st.pop();
                }
            } else {
                st.push(x);
            }
        }
        if (st.size() == 0){
            return true;
        } 
        return false;
    }
};
