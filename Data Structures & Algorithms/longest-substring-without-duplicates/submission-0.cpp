class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> se;
        int l=0,r= 0;
        int c = 0;
        for(auto x : s){
            while(se.find(x)!=se.end()){
                se.erase(s[l]);
                l++;
            }
            se.insert(x);
            r++;
            c = max(c , r - l);
        }
        return c;
    }
};
