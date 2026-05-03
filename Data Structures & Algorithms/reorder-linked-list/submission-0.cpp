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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* ptr = head;
        ListNode* newList= new ListNode(0);
        int n=0;
        while(ptr!=nullptr){
            n++;
            nodes.push_back(ptr);
            ptr=ptr->next;
        }
        if(nodes.size()<3){
            return;
        }
        // for(int i=0, j = nodes.size()-1 ; i<=j ; i++,j--){
        //     if(i==j){
        //         p = nodes[i];
        //     }
        //     else{
        //         p = nodes[i];
        //         p->next = nodes[j];
        //         p=p->next->next;
        //     }
        // }
        int start=0;
        int end=n-1;
        ListNode* res=new ListNode(-1);
        ptr=res;
        while(start<end){
            ptr->next=nodes[start++];
            ptr=ptr->next;
            ptr->next=nodes[end--];
            ptr=ptr->next;
        }
        if(start==end){
            ptr->next=nodes[end];
            ptr=ptr->next;
        }
        ptr->next=nullptr;
        head=res->next;

    }
};
