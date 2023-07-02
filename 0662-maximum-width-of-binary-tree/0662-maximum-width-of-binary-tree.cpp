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
    int ans=0;
    void helper(TreeNode*root)
    {
        queue<pair<TreeNode*,long long int >>qu;
        qu.push({root,0});
        
        while(!qu.empty())
        {
            int quSize=qu.size();
            long long int leftmost=0,rightmost=0;
            long long start = qu.front().second;
            for(int i=0;i<quSize;i++)
            {
                pair<TreeNode*,long long int>element=qu.front();
                qu.pop();
                TreeNode* node=element.first;
                long long int idx=element.second-start;
                if(i==0)leftmost=idx;
                if(i==quSize-1)rightmost=idx;
                // cout<<element.first->val<<endl;
                if(node->left!=NULL)qu.push({node->left,(long long)2*idx+1});
                if(node->right!=NULL)qu.push({node->right,(long long)2*idx+2});
                
            }
            int width=rightmost-leftmost+1;
            ans=max(ans,width);
            
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans;
    }
};