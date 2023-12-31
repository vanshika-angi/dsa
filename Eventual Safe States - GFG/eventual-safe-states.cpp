//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
//   bool dfs(int node, vector<int> adj[], vector<int>&vis, vector<int>&pathvis,vector<int>&check)
//     {
//         vis[node]=1;
//         pathvis[node]=1;
//         check[node]=0;
//         for(auto it:adj[node])
//         {
//             if(!vis[it])
//             {
//                 if(dfs(it,adj,vis,pathvis,check)==true)return true;
//             }
//             else if(pathvis[it])
//             {
//                 return true;
//             }
//         }
//         check[node]=1;
//         pathvis[node]=0;
//         return false;
//     }
    
    
//     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//         vector<int>vis(V,0);
//         vector<int>pathvis(V,0);
//         vector<int>safe;
//         vector<int>check(V,0);
//         for(int i=0;i<V;i++)
//         {
//             if(!vis[i])
//             {
//                 dfs(i,adj,vis,pathvis,check);
//             }
//         }
//         for(int i=0;i<V;i++)
//         {
//             if(check[i]==1)safe.push_back(i);
//         }
        
//         return safe;
//     }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        
        vector<int>adjR[V];
        vector<int>indegree(V,0);
        queue<int>q;
        vector<int>safe;
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                adjR[it].push_back(i);
                indegree[i]++;
                
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safe.push_back(node);
            
            for(auto it:adjR[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        
        sort(safe.begin(),safe.end());
        return safe;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends