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
    bool flag=true;
    int helper(TreeNode*root)
    {
        if(root==NULL || flag==false)return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        if(l-r<-1 || l-r>1)flag=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
      if(root==NULL)return true;
      helper(root);
        return flag;
    }
};