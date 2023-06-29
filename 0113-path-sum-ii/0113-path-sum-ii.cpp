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
    vector<vector<int>> res;
    void helper(TreeNode* root,int targetSum, int& sum,vector<int>& temp)
    {
        if(root==NULL)return ;
        sum=sum+root->val;
        temp.push_back(root->val);
        if(sum==targetSum && root->left==NULL && root->right==NULL)
        {
            res.push_back(temp);
        }
        helper(root->left,targetSum,sum,temp);
        helper(root->right,targetSum,sum,temp);
        sum=sum-root->val;
        temp.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;
        helper(root,targetSum, sum,temp);
        return res;
        
    }
};