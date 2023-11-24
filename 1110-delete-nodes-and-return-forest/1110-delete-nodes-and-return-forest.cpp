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
    unordered_map<int,bool>mp;
    TreeNode* treeRunning(TreeNode* root, vector<TreeNode*>&res)
    {
        if(root==NULL)return NULL;
        
        root->left = treeRunning(root->left,res);
        root->right = treeRunning(root->right,res);
        
        if(mp.find(root->val)!=mp.end())
        {
            // cout<<root->val<<endl;
            if(root->left!=NULL)
            {
                res.push_back(root->left);
            }
            if(root->right!=NULL)
            {
                res.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      for(auto x:to_delete)
      {
         mp[x]=true; 
      }
        
        vector<TreeNode*>res;
        
        if(treeRunning(root,res))
        {
            res.push_back(root);
        }
       return res;
    }
};