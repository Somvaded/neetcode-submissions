class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>> >timemap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
       vector<pair<int,string>>& timevector = timemap[key];
       timevector.push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& timevector = timemap[key];
        int l = 0, r = timevector.size()-1;
        int res = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(timevector[mid].first < timestamp){
                res = mid;
                l = mid+1;
            } else if(timevector[mid].first > timestamp){                
                r= mid -1;
            }
            else{
                res = mid;
                break;
            }
        }
        if (res == -1 ){
            return "";
        }
        return timevector[res].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */