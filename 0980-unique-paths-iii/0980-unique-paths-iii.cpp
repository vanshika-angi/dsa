class Solution {
public:
    int n,m;
    int pathcount(vector<vector<int>>& grid,int x,int y,int dx,int dy,vector<vector<bool>>&visited,int count)
    {
        if(x==dx && y==dy)
        {
            if(count==0)return 1;
            return 0;
        }
        
        if(x<0 || y<0 || x>=n || y>=m || visited[x][y]==1 || grid[x][y]==-1)return 0;
        
        visited[x][y]=true;
        
        int res = pathcount(grid,x-1,y,dx,dy,visited,count-1) + 
            pathcount(grid,x+1,y,dx,dy,visited,count-1) +
            pathcount(grid,x,y-1,dx,dy,visited,count-1) + 
            pathcount(grid,x,y+1,dx,dy,visited,count-1);
        
        visited[x][y]=false;
        return res;
            
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
      int sx=0,sy=0,dx=0,dy=0;
        int count=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==2)
                {
                    dx=i;
                    dy=j;
                }
                else if(grid[i][j]==0)
                {
                    count++;
                }
            }
        }
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        return pathcount(grid,sx,sy,dx,dy,visited,count+1);
    }
};