//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //     vector<int>vis(V,0);
    //     int sum=0;
    //     pq.push({0,0});
        
    //     while(!pq.empty())
    //     {
    //         auto it=pq.top();
    //         pq.pop();
    //         int node=it.second;
    //         int wt=it.first;
            
    //         if(vis[node]==1)continue;
    //         vis[node]=1;
    //         sum+=wt;
    //         for(auto it:adj[node])
    //         {
    //             int adjnode=it[0];
    //             int adjwt=it[1];
    //             if(!vis[adjnode])
    //             {
    //                 pq.push({adjwt,adjnode});
    //             }
    //         }
    //     }
        
    //     return sum;
    // }
    
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i]){
                int adjnode=it[0];
                int wt=it[1];
                int node=i;
                
                edges.push_back({wt,{node,adjnode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        DisjointSet d1(V);
        int sum=0;
        for(auto it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
                if(d1.findParent(u)!=d1.findParent(v)){
                sum+=wt;
                d1.unionBySize(u,v);
            }
        }
        
        return sum;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends