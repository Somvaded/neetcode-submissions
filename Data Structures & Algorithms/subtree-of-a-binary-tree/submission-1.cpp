/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool ans = false;
    bool check(TreeNode* p , TreeNode* q){
        if(!q && !p){
            return true;
        }
        if((p && q) && p->val == q->val){
            return check(p->left,q->left) && check(p->right , q->right);
        }
        else{
            return false;
        }
    } 
    void dfs(TreeNode* root,TreeNode* subRoot){
        if(root==nullptr){
            return;
        }
        dfs(root->left,subRoot);
        dfs(root->right,subRoot);
        if(root->val == subRoot->val){
            ans = ans || check(root,subRoot);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        dfs(root,subRoot);
        return ans;

    }
};
