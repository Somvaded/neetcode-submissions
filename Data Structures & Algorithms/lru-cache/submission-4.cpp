class LRUCache {
private:
    unordered_map<int,int> c;
    int cap;
    vector<int> order;
public:
    LRUCache(int capacity) {
        cap= capacity;
        order.resize(cap,0);
    }
    
    int get(int key) {
        if(c.find(key)==c.end()){
            return -1;
        }
        for(int i =0 ; i<cap;i++){
            if(order[i]==key){
                order.erase(order.begin()+i);
                order.push_back(key);
            }
        }
        return c[key];
    }
    
    void put(int key, int value) {
        if(c.find(key)!=c.end()){
            for(int i =0 ; i<cap;i++){
                if(order[i]==key){
                    order.erase(order.begin()+i);
                    order.push_back(key);
                    c[key]=value;
                }
            }
        }
        else if(order.size()==cap){
            c.erase(order[0]);
            order.erase(order.begin());
            order.push_back(key);
            c[key]=value;
        }
        else{
            order.push_back(key);
            c[key]=value;
        }
    }
};
