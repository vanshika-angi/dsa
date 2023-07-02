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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd, int postStart,int postEnd)
    {
        if(postStart>postEnd || inStart>inEnd)return NULL;
        
        TreeNode* root=new TreeNode(postorder[postEnd]);
        
        int idx = mp[root->val];
        int numsRight=inEnd-idx;
        
        root->left=helper(inorder,postorder,inStart,idx-1,postStart,postEnd-numsRight-1);
        root->right=helper(inorder,postorder,idx+1,inEnd,postEnd-numsRight,postEnd-1);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)return NULL;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};