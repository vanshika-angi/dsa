/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
      if(mp.find(node)==mp.end())  
      {
          Node* newNode = new Node(node->val);
          mp[node]=newNode;
      }
       Node * curr = mp[node]; 
       cout<<curr->val<<endl;
      for(auto it:node->neighbors) 
      {
          Node* temp = it;
          if(mp.find(temp)==mp.end())
            curr->neighbors.push_back(cloneGraph(temp));
          else 
            curr->neighbors.push_back(mp[temp]);
          
      } 

      return curr;
    }
};