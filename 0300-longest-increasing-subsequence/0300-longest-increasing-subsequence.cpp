class Solution {
public:
    int f(int ind,int lar_ind,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(ind<0)return 0;
        if(dp[ind][lar_ind+1]!=-1)return dp[ind][lar_ind+1];
        int npick = 0+ f(ind-1,lar_ind,nums,dp);
        int pick =INT_MIN;
        if(lar_ind==-1 || nums[lar_ind]>nums[ind])
        {
           pick = 1 + f(ind-1,ind,nums,dp); 
        }
        
        return dp[ind][lar_ind+1] = max(npick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return f(n-1,-1,nums,dp); 
    }
};