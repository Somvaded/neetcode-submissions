class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(auto x : strs){
            encoded +=to_string(x.size()) + "%" + x ;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='%'){
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            string temp = s.substr(j+1,length);
            decoded.push_back(temp);
            i=j+1+length;
        }
        return decoded;

    }
};
