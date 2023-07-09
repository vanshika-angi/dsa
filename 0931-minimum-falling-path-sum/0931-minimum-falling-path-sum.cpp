class Solution {
public:
    long long int f(int i,int j,vector<vector<int>>& matrix,int n,vector<vector<int>>&dp)
    {
        if(i<0 || i>=n|| j<0 ||j>=n)return INT_MAX;
        if(i==n-1) return matrix[i][j];
        
        if(dp[i][j]!=-200)return dp[i][j];
        long long int call1=f(i+1,j,matrix,n,dp)+matrix[i][j];
        long long int call2=f(i+1,j-1,matrix,n,dp)+matrix[i][j];
        long long int call3= f(i+1,j+1,matrix,n,dp)+matrix[i][j];
        
        return dp[i][j] = min(call1,min(call2,call3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-200));
        for(int i=0;i<n;i++)
        {
            ans = min(  ans, f(0,i,matrix,n,dp) );
        }
        
        return ans;
    }
};