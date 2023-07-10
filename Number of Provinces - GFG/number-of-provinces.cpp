//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node,int V,vector<int> adj[],vector<int>&vis)
    {
        vis[node]=1;
        //dfs traversals
        for(auto it:adj[node])
        {
            if(vis[it]==0)dfs(it,V,adj,vis);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adjLs[V];
        
        //to change adjaceny matric to adjaceny list
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(j);
                }
            }
        }
        
        
        vector<int>vis(V,0);
        int provinces=0;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,V,adjLs,vis);
                provinces++;
                
            }
        }
        
        return provinces;
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