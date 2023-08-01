class Solution {
public:
    int helper(int ind,int lar_ind,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(ind<0)return 0;
        if(dp[ind][lar_ind+1]!=-1)return dp[ind][lar_ind+1];
        int notpick = 0 + helper(ind-1,lar_ind,nums,dp);
        int pick=INT_MIN;
        if(lar_ind==-1 || nums[ind]<nums[lar_ind])
            pick = 1+helper(ind-1,ind,nums,dp);
        
        return dp[ind][lar_ind+1] = max(notpick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=i+1;j<=n;j++)
//             {
//                 int notpick = 0 + dp[i-1][j];
//                 int pick=INT_MIN;
//                 if( nums[i-1]<nums[j-1])
//                     pick = 1+dp[i-1][i-1];
                
//                 dp[i][j] = max(notpick,pick);
//             }
//         }
//         return dp[n-1][n-1];
       return helper(n-1,-1,nums,dp); 
    }
};