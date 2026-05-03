class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>> ans;
     for(auto s : strs){
        vector<int> count(26,0);
        for(char k : s){
            count[k-'a']++;
        }
        string key="";
        for(int c: count){
            key+="#" + to_string(c);
        }
        ans[key].push_back(s);
     }   
     vector<vector<string>> res;
     for(auto a : ans){
        res.push_back(a.second);
     }
     return res;
    }
};
