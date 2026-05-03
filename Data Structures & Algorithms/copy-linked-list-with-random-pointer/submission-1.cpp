/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> rand;
        rand[nullptr]=nullptr;   
        Node* curr = head;
        while(curr!=nullptr){
            Node* newcopy = new Node(curr->val);
            rand[curr]=newcopy;
            curr=curr->next;
        }  
        curr=head;
        while(curr!=nullptr){
            Node* copy = rand[curr];
            copy->next = rand[curr->next];
            copy->random = rand[curr->random];
            curr=curr->next;
        }
        return rand[head];
    }
};
