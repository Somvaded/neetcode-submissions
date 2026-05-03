class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int res=0;
        vector<int> count(26,0);
        int maxc = 0;
        while(j<s.size()){
            count[s[j]-'A']++;
            maxc = max(count[s[j]-'A'],maxc);
            if(j-i+1-maxc > k){
                count[s[i]-'A']--;
                i++;
            }
            res = max(res , j-i+1);
            j++;

        }
        return res;
    }
};
