struct Node{
    vector<Node*> children;
    bool end;
    

    Node() : children(26, nullptr), end(false) {}
};


class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for( char x : word){
            if(curr->children[x -'a'] == nullptr){
                curr->children[x - 'a'] = new Node();
            }
            curr = curr->children[x - 'a'];
        }
        curr -> end  = true;
    }
    bool helper(int start,string word, Node* curr){
        for(int i = start ; i< word.size() ; i++){
            if(word[i] == '.'){
                for(auto x : curr-> children){
                   if(x != nullptr && helper(i+1 , word , x)){
                      return true;
                   }
                }
                return false;
            }
            else{
                if(curr->children[word[i] - 'a'] == nullptr){
                    return false;
                }
                curr = curr->children[word[i] - 'a'];
            }
        }
        return curr->end;
    }
    bool search(string word) {
        return helper(0,word,root);
    }
};
