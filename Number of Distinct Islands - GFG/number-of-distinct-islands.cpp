//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int>delrow{-1,0,1,0};
    vector<int>delcol{0,1,0,-1};
    int n,m;
    void dfs(int i,int j,vector<vector<int>>&vis, vector<vector<int>>& grid,vector<pair<int,int>>&vec, int row0,int col0)
    {
        vis[i][j]=1;
        vec.push_back({i-row0,j-col0});
        
        for(int c=0;c<4;c++)
        {
            int nrow=i+delrow[c];
            int ncol=j+delcol[c];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,grid,vec,row0,col0);
            }
        }
        
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                    
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends