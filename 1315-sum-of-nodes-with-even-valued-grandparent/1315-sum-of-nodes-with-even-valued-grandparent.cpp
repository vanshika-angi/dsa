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
    int sum=0;
    void helper(TreeNode*parent)
    {
        if(parent==NULL)return;
        if(parent->left!=NULL)sum=sum+parent->left->val;
        if(parent->right!=NULL)sum=sum+parent->right->val;
    }
    int sumEvenGrandparent(TreeNode* root) {
      if(root==NULL)return 0; 
        
        if((root->val)%2==0)
        {
            helper(root->left);
            helper(root->right);
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum;
    }
};