/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_track)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left!=NULL)
            {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right!=NULL)
            {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*,TreeNode*>parent_track;
        mark_parent(root,parent_track);
        
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        
        q.push(target);
        vis[target]=true;
        
        int level=0;
        
        while(!q.empty())
        {
            int qsize=q.size();
            if(level++ == k)break;
            
            for(int i=0;i<qsize;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left!=NULL && vis[node->left]==false)
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                
                if(node->right!=NULL  && vis[node->right]==false)
                {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                
                if(parent_track[node] && vis[parent_track[node]]==false)
                {
                    q.push(parent_track[node]);
                    vis[parent_track[node]]=true;
                }
            }
            
        }
        
        vector<int>result;
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        
        return result;
        
    }
};