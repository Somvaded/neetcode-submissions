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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroup = dummy;
        while(true){
            ListNode* kth = kthNode(prevGroup,k);
            if(!kth){
                break;
            } 
            ListNode* nextGroup = kth->next;
            ListNode* curr=prevGroup->next;
            ListNode* prev = kth->next;

            while(curr!=nextGroup){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }
        return dummy->next;
        
    }
    ListNode* kthNode(ListNode* head , int k){
        while(head && k>0){
            head=head->next;
            k--;
        }
        return head;
    }
};
