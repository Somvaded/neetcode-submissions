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
   TreeNode* helper(vector<int>& preorder, vector<int>& inorder){
       if(preorder.empty() || inorder.empty()){
        return nullptr;
       }
       TreeNode* root = new TreeNode(preorder[0]);
       int inRoot;
       for(int i = 0;i<inorder.size();i++){
          if(inorder[i]==preorder[0]){
            inRoot = i;            
          }
       }
       vector<int> leftPreTree(preorder.begin()+1,preorder.begin()+inRoot+1);
       vector<int> rightPreTree(preorder.begin()+inRoot+1,preorder.end());

       vector<int> leftInTree(inorder.begin(),inorder.begin()+inRoot);
       vector<int> rightInTree(inorder.begin()+inRoot+1,inorder.end());

       root->left = helper(leftPreTree,leftInTree);
       root->right = helper(rightPreTree, rightInTree);
       return root;

       
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder);
    }
};
