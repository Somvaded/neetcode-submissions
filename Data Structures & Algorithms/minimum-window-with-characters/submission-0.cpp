class Solution {
public:
    string minWindow(string s, string t) {
       if(t == "" || t.length() > s.length()){
        return "";
       }
       unordered_map<char,int> countT;
       unordered_map<char,int> window;
       for(auto x : t){
        countT[x]++;
       } 
       int have=0,need=countT.size(); 
       int l = 0;
       string res="";
       int resL=INT_MAX;
       for(int r=0;r<s.length();r++){
            window[s[r]]++;
            if(countT.find(s[r])!=countT.end() && countT[s[r]]==window[s[r]]){
                have++;
            }
            while(have == need) {
                if(r-l+1 < resL){
                    resL = r - l + 1;
                    res = s.substr(l,resL);
                }
                window[s[l]]--;
                if(countT.find(s[l])!=countT.end() && window[s[l]]<countT[s[l]]){
                    have--;
                }
                l++;
            }
       }
       return resL == INT_MAX ? "" : res;
    }
};
