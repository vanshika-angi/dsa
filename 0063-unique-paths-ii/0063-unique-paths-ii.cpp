class Solution {
public:
    int m;
    int n;
    // int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    // {
    //     // cout<<i<<" "<<j<<endl;
    //     if(i>=0 && j>=0 && obstacleGrid[i][j]==1)return 0;
    //     if(i>m-1 || j>n-1 ||i<0||j<0)return 0;
    //     if(i==0  && j==0)return dp[0][0] = 1;
        
        
    //     if(dp[i][j]!=-1)return dp[i][j];
        
    //     int up=f(i-1,j,obstacleGrid,dp);
    //     int left=f(i,j-1,obstacleGrid,dp);
        
    //     return dp[i][j] = up+left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 &&j==0)continue;
                else
                {
                    // cout<<i<<j<<endl;
                    if(i>0)dp[i][j]+=dp[i-1][j];
                    if(j>0)dp[i][j]+=dp[i][j-1];
                }
            }
        }

    //   for(int i=0;i<m;i++)
    //   {
    //       for(int j=0;j<n;j++)
    //       {
    //           cout<<dp[i][j]<<" ";
    //       }cout<<endl;
    //   }
      return dp[m-1][n-1];
    }
};


//Memoization
// class Solution {
// public:
//     int m;
//     int n;
//     int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
//     {
//         // cout<<i<<" "<<j<<endl;
//         if(i>=0 && j>=0 && obstacleGrid[i][j]==1)return 0;
//         if(i>m-1 || j>n-1 ||i<0||j<0)return 0;
//         if(i==0  && j==0)return dp[0][0] = 1;
        
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int up=f(i-1,j,obstacleGrid,dp);
//         int left=f(i,j-1,obstacleGrid,dp);
        
//         return dp[i][j] = up+left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         m=obstacleGrid.size();
//         n=obstacleGrid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//       return f(m - 1, n - 1, obstacleGrid, dp); 
//     //   return dp[m-1][n-1];
//     }
// };