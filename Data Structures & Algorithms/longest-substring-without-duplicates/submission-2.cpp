class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> c;
        int i = 0;
        int j = 0;
        int res = 0;
        while(i <= j && j<s.length()){
            while(c.find(s[j]) != c.end()){
                    c.erase(s[i]);
                    i++;
            }
            c.insert(s[j]);
            j++;
            res = max(res, j-i);
        }
        return res;
    }
};
