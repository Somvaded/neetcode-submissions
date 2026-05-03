class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> a1(26,0);
        vector<int> a2(26,0);
        for(int i=0;i<s1.size();i++){
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;

        }
        int i=0;
        int j=s1.size()-1;
        while(j<s2.size()){
            bool found = true;
            for(int r=0;r<26;r++){
                if(a1[r]!=a2[r]){
                    j++;
                    a2[s2[j]-'a']++;
                    a2[s2[i]-'a']--;
                    i++;
                    found = false;
                    break;
                }
            }
            if(found == true){
                return true;
            }
        }
        return false;
    }
};
