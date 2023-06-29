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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>>res;
       if(root==NULL)return res;
       queue<TreeNode*>qu;
       qu.push(root);
       while(!qu.empty())
       {
           vector<int>temp;
           int levelSize = qu.size();
           for(int i=0;i<levelSize;i++)
           {
               TreeNode* element = qu.front();
               qu.pop();
               temp.push_back(element->val);
                if(element->left!=NULL){
                    qu.push(element->left);
                }
                if(element->right!=NULL){
                    qu.push(element->right);
                }
           }
           res.push_back(temp);
       } 
       int n=res.size();
       int low=0,high=n-1;
       while(low<high)
       {
           vector<int>temp=res[low];
           res[low]=res[high];
           res[high]=temp;
           low++;
           high--;
       }
       return res;
    }
};