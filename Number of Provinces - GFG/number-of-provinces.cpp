//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    vector<int>rank,parent,size;
    
public:

    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findParent(int node)
    {
        if(node==parent[node])return node;
        else return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u,int v)
    {
        int upu=findParent(u);
        int upv=findParent(v);
        if(upu==upv)return;
        
        if(rank[upu]<rank[upv])
        {
            parent[upu]=upv;
        }
        else if(rank[upv]<rank[upu])
        {
            parent[upu]=upv;
        }
        else
        {
           parent[upu]=upv; 
           rank[upu]++;
        }
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
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)ds.unionBySize(i,j);
            }
        }
        
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(ds.findParent(i)==i)cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends