class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                int call1=dp[i-1][j]+matrix[i][j];
                dp[i][j]=call1;
                if(j-1>=0){
                   int call2 = dp[i-1][j-1] + matrix[i][j]; 
                    dp[i][j]=min(dp[i][j],call2);
                }
                    
                if(j+1<n)
                {
                    int call3=dp[i-1][j+1]+matrix[i][j];
                    dp[i][j]=min(dp[i][j],call3);
                }      
            }  
        }
    
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        
        return ans;
    }
};

