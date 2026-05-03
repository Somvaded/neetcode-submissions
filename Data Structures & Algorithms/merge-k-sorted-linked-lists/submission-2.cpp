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
    ListNode* Sort(ListNode* one, ListNode* two){
        ListNode* ans = new ListNode(-1);
        ListNode* ptr = ans;
        while(one!=nullptr && two!=nullptr){
            if(one->val<=two->val){
                ListNode* temp = new ListNode(one->val);
                ptr->next = temp; 
                one = one->next;
            }
            else{
                ListNode* temp = new ListNode(two->val);
                ptr->next = temp;
                two = two->next;
            }
            ptr=ptr->next;
        }
        while(one!=nullptr){
                ListNode* temp = new ListNode(one->val);
                ptr->next = temp; 
                one = one->next;
                ptr=ptr->next;

        } 
        while(two!=nullptr){
            ListNode* temp = new ListNode(two->val);
            ptr->next = temp;
            two = two->next;
            ptr=ptr->next;

        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        if(lists.size()==1){
            return lists[0];
        }
        int n = lists.size();
        int i=0;
        while(lists.size()>1){
            vector<ListNode*> newList;
            for(int i=0;i<lists.size();i+=2){
                if(i==lists.size()-1){
                    newList.push_back(lists[i]);
                    break;
                }
                ListNode* temp = Sort(lists[i],lists[i+1]);
                newList.push_back(temp);
            }
            lists=newList;
        }    
        return lists[0];    
    }

};
