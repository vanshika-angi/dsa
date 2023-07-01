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
    TreeNode* findLastRight(TreeNode*root)
    {
        if(root->right==NULL)return root;
        return findLastRight(root->right);
    }
    TreeNode* helper(TreeNode*root)
    {
        if(root->left==NULL)return root->right;
        if(root->right==NULL)return root->left;

        TreeNode*temp=root->right;
        TreeNode* lastRight=findLastRight(root->left);
        lastRight->right=temp;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* curr, int key) {
        if(curr==NULL)return NULL;
        if(curr->val==key)return helper(curr);

        TreeNode*root=curr;

        while(root!=NULL)
        {
            if(root->val>key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left=helper(root->left);
                }
                else
                {
                    root=root->left;
                }
            }
            else
            {
               if(root->right!=NULL && root->right->val==key)
                {
                    root->right=helper(root->right);
                }
                else
                {
                    root=root->right;
                }
            } 
            }

            return curr;
        }
    
};