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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> list1,list2;
        while(l1!=nullptr){
            list1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            list2.push_back(l2->val);
            l2=l2->next;
        }
        int i=0;
        int j =0;
        int carry=0;
        vector<int> res;
        while(i<list1.size() || j<list2.size()){
            if(i<list1.size() && j<list2.size()){
                int temp = carry + list1[i] + list2[j];
                carry = temp/10;
                res.push_back(temp%10);
                i++;j++;
            }
            else if(i<list1.size()){
                int temp = carry+list1[i];
                carry = temp/10;
                res.push_back(temp%10);
                i++;
            }
            else{
                int temp = carry+list2[j];
                carry = temp/10;
                res.push_back(temp%10);
                j++;
            }
        }
        if(carry!=0){
            res.push_back(carry);
        }
        ListNode* answer = new ListNode(-1);
        ListNode *ptr = answer;
        for(auto x : res){
            ListNode* temp = new ListNode(x);
            ptr->next = temp;
            ptr=ptr->next;
            
        }
        return answer->next;
    }
};
