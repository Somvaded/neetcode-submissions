
struct Node {
    Node* list[26];
    bool flag = false;
};


class PrefixTree {
    Node * root;
public: 
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto x : word){
            if(!node->list[x-'a']){
                node->list[x-'a'] = new Node();
            }
            node = node->list[x-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto x : word){
            if(!node->list[x-'a']){
                return false;
            }
            node = node->list[x-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
         Node* node = root;
        for(auto x : prefix){
            if(!node->list[x-'a']){
                return false;
            }
            node = node->list[x-'a'];
        }
        return true;
    }
};
