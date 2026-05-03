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
    ListNode* helper(ListNode* ptr , int& n){
        if(ptr==nullptr){
            return nullptr;
        }
        ptr->next=helper(ptr->next,n);
        n--;
        if(n==0){
            return ptr->next;
        }
        return ptr;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head,n);
    }
};
