//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int n,m;
    // Function to find the number of islands.
    
    void dfs(int row, int col,vector<vector<int>>&vis,vector<vector<char>>& grid)
    {
        vis[row][col]=1;
        
        for(int delrow=-1;delrow<2;delrow++)
        {
            for(int delcol=-1;delcol<2;delcol++)
            {
                int nrow = row+delrow;
                int ncol = col+delcol;
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m 
                && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
                {
                    dfs(nrow,ncol,vis,grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int islands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    dfs(i,j,vis,grid);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends