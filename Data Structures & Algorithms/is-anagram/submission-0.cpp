class Solution {
public:
    bool isAnagram(string s, string t) {
        char str1[26]={0};
        char str2[26]={0};
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            str1[s[i]-'a']++;
            str2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(str1[i]!=str2[i]){
                return false;
            }
        }
        return true;
    }
};
