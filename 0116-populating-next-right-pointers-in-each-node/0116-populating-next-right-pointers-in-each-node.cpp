/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node*root)
    {
        if(root==NULL)return;
        queue<Node*>qu;
        qu.push(root);
        
        while(!qu.empty())
        {
            int quSize=qu.size();
            for(int i=0;i<quSize;i++)
            {
                Node*element=qu.front();
                qu.pop();
                
                if(i==quSize-1) element->next=NULL;
                else  element->next=qu.front();
                
                if(element->left)qu.push(element->left);
                if(element->right)qu.push(element->right);
            }
        }
    }
    Node* connect(Node* root) {
       helper(root); 
        return root;
    }
};