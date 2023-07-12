class Solution {
public:
    // int ans=INT_MAX;
//     int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp)
//     {
//         if(ind==coins.size()-1)
//         {
//             // cout<<ind<<" "<<amount<<endl;
//             if(amount%coins[ind]==0)return amount/coins[ind];
//             return 1e9;
//         }
//         if(dp[ind][amount]!=-1)return dp[ind][amount];
        
//         int notpick = f(ind+1,amount,coins,dp);
//         int pick=1e9;
//         if(amount-coins[ind]>=0)pick = 1 + f(ind,amount-coins[ind],coins,dp);
//         return dp[ind][amount]=min(notpick,pick);
//     }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(i>=coins[j])dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
        
       return dp[amount]>=1e9?-1:dp[amount];
        
    }
};