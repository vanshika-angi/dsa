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
    void helper(TreeNode*root)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)return;
        helper(root->right);
        helper(root->left);
        
        TreeNode*temp=root->right;
        if(root->left!=NULL)
        {
            root->right=root->left;
            root->left=NULL;
            TreeNode*curr=root->right;
            while(curr->right!=NULL)
            {
                curr=curr->right;
            }
            curr->right=temp;
        }
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};