//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfsdetect(int src,vector<int> adj[],vector<int>&vis)
    {
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        //bfs traversing
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    q.push({it,node});
                    vis[it]=1;
                }
                //Node is already visited but it is not parent it means it has already been visited in cycle
                else if(it!=parent)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
    
    bool dfs(int node,int parent,vector<int>&vis, vector<int> adj[])
    {
        vis[node]=1;
        
        for(auto adjacentNode: adj[node])
        {
            //if neighbour is not visiited, go into depth of it
            if(!vis[adjacentNode])
            {
                //if we detect cycle in future.
                if(dfs(adjacentNode,node,vis,adj)==true)
                return true;
            }
            //adjaceentNode has been already presennt in path and it is not parent, meaning it is a cyel
            else if(adjacentNode!=parent)
            {
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int>vis(V,0);
        
        
        
        for(int i=0;i<V;i++)
        {
            //This for loop is required for component graphs
            if(!vis[i])
            {
                if(dfs(i,-1,vis,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends