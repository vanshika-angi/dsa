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
    stack<TreeNode*>inorder;
    stack<TreeNode*>rev_inorder;
    
    void populateInorder(TreeNode*root)
    {
        while(root!=NULL)
        {
            inorder.push(root);
            root=root->left;
        }
    }
    void populateRevInorder(TreeNode*root)
    {
        while(root!=NULL)
        {
            rev_inorder.push(root);
            root=root->right;
        }
    }
    TreeNode* next()
    {
        if(!inorder.empty())
        {
            TreeNode*element=inorder.top();
            inorder.pop();
            
            if(element->right)populateInorder(element->right);
            return element;
        }
        return NULL;
        
    }
    
    TreeNode* prev()
    {
        if(!rev_inorder.empty())
        {
            TreeNode*element=rev_inorder.top();
            rev_inorder.pop();
            
            if(element->left)populateRevInorder(element->left);
            return element;
        }
        return NULL;
    }
    bool findTarget(TreeNode* root, int k) {
        populateInorder(root);
            populateRevInorder(root);
        TreeNode* l = next();
        TreeNode* r = prev();
        
        while(l->val<r->val)
        {
            int sum=l->val+r->val;
            if(sum>k && !rev_inorder.empty())r=prev();
            else if(sum<k && !inorder.empty())l=next();
            else return true;
        }
        
        return false;
    }
};