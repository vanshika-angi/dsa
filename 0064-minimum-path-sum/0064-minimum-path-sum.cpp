class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
        if(n==1&&m==1)return grid[0][0];
      vector<vector<int>> dp(n+1,vector<int>(m+1,0));

      for(int i=0;i<=n;i++)
      {
          dp[i][0]=INT_MAX;
      }  
      for(int i=0;i<=m;i++)
      {
          dp[0][i]=INT_MAX;
      } 

      dp[1][1]=grid[0][0];

      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          {
              if(i==1&&j==1)
              {
                //   cout<<"x";
                  dp[i][j]=grid[0][0];

              }
              else
              {
                  cout<<i<<" "<<j<<endl;
                  dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
              }
          }
      }

    //   for(int i=0;i<=n;i++)
    //   {
    //       for(int j=0;j<=m;j++)
    //       {
    //           cout<<dp[i][j]<<" ";
    //       }cout<<endl;
    //   }
    return dp[n][m];
      
    }
};