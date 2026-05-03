class TimeMap {
private:
     unordered_map<string,vector<pair<string,int>>> stamp;
public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        stamp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(stamp.find(key)==stamp.end()){
            return "";
        }
        string result="";
        int l= 0;
        int r = stamp[key].size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(stamp[key][mid].second<=timestamp){
                result = stamp[key][mid].first;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result;

    }
};
