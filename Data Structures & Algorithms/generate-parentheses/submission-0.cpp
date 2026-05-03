class Solution {
public:
    vector<string> temp;
    void helper(int n, int open,int close,string ans){
        if(open==close && open==n){
            temp.push_back(ans);
            return;
        }
        if(open<n){
            helper(n, open+1,close,ans+'(');
        }
        if(close<open){
            helper(n, open , close+1 , ans+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        helper(n,0,0,"");
        return temp;   
    }
};
