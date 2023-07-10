class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       queue<pair<pair<int,int>,int>>q;
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>delrow{-1,0,1,0};
        vector<int>delcol{0,1,0,-1};
        int tm=0;
        
        //pushing rotten oranges
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    // cnt++;
                }
                else if(grid[i][j]==1)cnt++;
            }
        }
        
        
        //checking time required to rot all oranges
        int orange=0;
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            tm=max(tm,time);
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m 
                   && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
                {
                    // cout<<nrow<<" "<<ncol<<endl;
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                    orange++;
                    q.push({{nrow,ncol},time+1});
                    
                }
            }   
        }
        
        // cout<<cnt<<endl;
        if(orange!=cnt)return -1;
        
        return tm;
    }
};