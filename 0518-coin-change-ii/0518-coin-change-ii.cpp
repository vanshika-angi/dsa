class Solution {
public:
    int n;
    // int helper(int ind,int amount,vector<int>&coins)
    // {
    //     if(amount==0)return 1;
    //     if(ind ==0){
    //         if(amount%coins[0]==0)return 1;
    //         else return 0;
    //     }
        
    //     int notpick = helper(ind-1,amount,coins);
    //     int pick=0;
    //     if(amount-coins[ind]>=0)pick = helper(ind,amount-coins[ind],coins);
    //     return pick+notpick;
         
    // }

    // int helper_memo(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp)
    // {
    //     if(dp[ind][amount] != -1)return dp[ind][amount];
    //     int notpick = helper_memo(ind-1,amount,coins,dp);
    //     int pick=0;
    //     if(amount-coins[ind]>=0)pick = helper_memo(ind,amount-coins[ind],coins,dp);
    //     return dp[ind][amount] = pick+notpick;  
    // }

    int helper_tab(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
               dp[i][j]=dp[i-1][j];
               if(j-coins[i]>=0)dp[i][j]+=dp[i][j-coins[i]]; 
            }
        }

        return dp[n-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0)return 1;
        n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=amount;i++)
        {
            if(i%coins[0]==0)dp[0][i]=1;
            else dp[0][i]=0;
        }

        return helper_tab(n-1,amount,coins,dp);
    }
};