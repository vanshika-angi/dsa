class Solution {
public:
    // int ans=INT_MAX;
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(ind==coins.size()-1)
        {
            // cout<<ind<<" "<<amount<<endl;
            if(amount%coins[ind]==0)return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        
        int notpick = f(ind+1,amount,coins,dp);
        int pick=1e9;
        if(amount-coins[ind]>=0)pick = 1 + f(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=min(notpick,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(0,amount,coins,dp);
       if (ans>=1e9)return -1;
       return ans;
        
    }
};