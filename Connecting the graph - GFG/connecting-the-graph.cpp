//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    
    
public:
    vector<int>parent,size;
    DisjointSet(int n)
    {
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findParent(int node)
    {
        if(node==parent[node])return node;
        else return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u,int v)
    {
        int upu=findParent(u);
        int upv=findParent(v);
        if(upu==upv)return;
        
        if(size[upu]<size[upv])
        {
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else 
        {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        
    }
    
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
      DisjointSet ds(n);
       int extraedge=0;
       for(auto it:edge)
       {
           
           int u=it[0];
           int v=it[1];
        //   cout<<u<<v<<endl;
          if(ds.findParent(u)!=ds.findParent(v))
          {
              ds.unionBySize(u,v);
          }
          else
          {
              ds.unionBySize(u,v);
              extraedge++; 
          }
       }
       int comp=0;
      for(int i=0;i<n;i++)
        {
          if(ds.parent[i]==i)comp++;  
        }       
    //   cout<<comp<<endl;
       if(comp-1<=extraedge)return comp-1;
       return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends