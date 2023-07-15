class Solution {
public:
    vector<int>delrow{-1,0,1,0};
    vector<int>delcol{0,1,0,-1};
    int n,m;
    
    void dfs(int i,int j,vector<vector<int>>& board, vector<vector<int>>&vis)
    {
        vis[i][j]=1;

        for(int c=0;c<4;c++)
        {
            int nrow=i+delrow[c];
            int ncol=j+delcol[c];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]==1)
            {
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& board) {
       
        n=board.size();
        m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]==1 && vis[i][j]==0)
                {
                    dfs(i,j,board,vis);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1 && vis[i][j]==0)ans++;
            }
        }
        
        return ans;
        
    }
};