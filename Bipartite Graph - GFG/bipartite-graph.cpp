//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // bool check(int node,int V,vector<int>adj[],vector<int>&color)
    // {
    //     queue<int>q;
	   // q.push(node);
    //       while(!q.empty())
    // 	    {
    // 	        int node=q.front();
    // 	        q.pop();
    	        
    // 	        for(auto itr:adj[node])
    // 	        {
    // 	            if(color[itr]==-1)
    // 	            {
    // 	                color[itr]=!color[node];
    // 	                q.push(itr);
    // 	            }
    // 	            else if(color[itr]==color[node])return false;
    // 	        }
    	        
    // 	    }
	    
	   // return true;  
    // }
    bool dfs(int node,int nodecolor, int V,vector<int>adj[],vector<int>&color)
    {
        color[node]=nodecolor;
        
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!nodecolor,V,adj,color)==false)return false;
            }
            else if(color[it]==nodecolor)
            {
                return false;
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	   
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(dfs(i,0,V,adj,color)==false)return false;
	        }
	        
	    }
	    return true;
	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends