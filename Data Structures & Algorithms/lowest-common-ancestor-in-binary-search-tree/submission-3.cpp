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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return root;
        }
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int s  = qt.size();
            while(s-->0){
                TreeNode* t = qt.front();
                qt.pop();
                if(max(p->val,q->val) < t->val){
                    qt.push(t->left);
                }
                else if(min(p->val,q->val) > t->val){
                    qt.push(t->right);
                }
                else{
                    return t;
                }
            }
        }
    }
};
