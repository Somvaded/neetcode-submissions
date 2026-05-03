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
    int mx = 0;
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = 1+ height(root->left);
        int right = 1 + height(root->right);
        return max(left,right);
    }
    void dfs(TreeNode* root){
        if(root==nullptr){
            return;
        }
        int left = height(root->left);
        int right = height(root->right);
        mx = max(mx ,left+right);
        dfs(root->left);
        dfs(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        dfs(root);
        return mx;
    }
};
