class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')' || s[0]=='}' || s[0]==']'){
            return false;
        }
        stack <char> open;
        open.push(s[0]);
        for(int i=1; i < s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                open.push(s[i]);
                continue;
            }
            if(open.empty()){
                return false;
            }
            char t = open.top();
             if(s[i]==')' && (t!='(')){
                return false;
            }
            else if(s[i]=='}' && (t!='{')){
                return false;
            }
            else if(s[i]==']' && (t!='[')){
                return false;
            }
            else{
                open.pop();
            }
        }
        return open.empty();
    }
};
