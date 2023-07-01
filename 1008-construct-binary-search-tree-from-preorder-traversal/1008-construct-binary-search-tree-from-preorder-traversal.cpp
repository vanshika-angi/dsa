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
    map<int,int>mp;
        TreeNode* helper(vector<int>& preorder, int preStart, int preEnd)
    {
        if(preStart>preEnd)return NULL;

        TreeNode*root = new TreeNode(preorder[preStart]);
        int numsLeft=numsLeftTree(root->val,preorder,preStart);
        root->left=helper(preorder,preStart+1,preStart+numsLeft);
        root->right=helper(preorder,preStart+numsLeft+1,preEnd);

        return root;


    }

    int numsLeftTree(int val,vector<int>preorder,int preStart)
    {
        int numLength=0;
        for(int i=preStart+1;i<preorder.size();i++)
        {
            if(preorder[i]<val)
            {
                numLength++;
        }
        else
        {
            break;
        }
        }
        return numLength;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        
        for(int i=0;i<preorder.size();i++)
        {
            mp[preorder[i]]=i;
        }
        TreeNode* root = helper(preorder,0,preorder.size()-1);
        return root;
        
    }
};