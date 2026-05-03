/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }

        if(lists.size()==0){
            return lists[0];
        }
        ListNode* answer = new ListNode(INT_MIN);

        for(int i=0 ;i<lists.size();i++){
            ListNode* curr = lists[i];
            ListNode* ptr = answer;
            while(curr!=nullptr){
                if(curr->val >= ptr->val){
                    while(ptr->next!=nullptr && ptr->next->val<curr->val){
                        ptr=ptr->next;
                    }
                    ListNode * newptr = new ListNode (curr->val);
                    if(ptr->next!=nullptr){
                        newptr->next = ptr->next;
                        ptr->next = newptr;
                    }
                    else{
                        ptr->next = newptr;
                    }
                }
                else{
                    ListNode * newptr = new ListNode (ptr->val);
                    if(ptr->val == INT_MIN){
                        ListNode* t = new ListNode  (curr->val);
                        ptr->next = t;
                    }
                    else{
                        ptr->val = curr->val;
                        newptr->next = ptr->next;
                        ptr->next = newptr; 
                    }
                }
                ptr=ptr->next;
                curr=curr->next;
            }
        }
        return answer->next;








    }
};
