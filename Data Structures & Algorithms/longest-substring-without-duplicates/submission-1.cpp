class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> c;
        int i = 0;
        int j = 0;
        int res = 0;
        while(i <= j && j<s.length()){
            if(c[s[j]] != 0){
                while(c[s[j]]!=0){
                    c[s[i]]--;
                    i++;
                }
            }
            c[s[j]]++;
            j++;
            int temp = j-i;
            res = max(res, temp);
        }
        return res;
    }
};
