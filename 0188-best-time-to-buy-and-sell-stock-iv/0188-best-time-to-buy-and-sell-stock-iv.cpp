class Solution {
public:
    int helper(int ind,int buy,int c,vector<int>& prices,vector<vector<vector<int>>>&dp)
    {
         if(c<=0)return 0;
        if(ind>=prices.size())return 0;
        if(dp[ind][buy][c]!=-1)return dp[ind][buy][c];
        int profit = 0;
        if(buy==1)
        {
            profit = max(-prices[ind] + helper(ind+1,0,c,prices,dp), helper(ind+1,1,c,prices,dp));
        }
        else if(buy==0 )
        {
            profit = max(prices[ind]+helper(ind+1,1,c-1,prices,dp),helper(ind+1,0,c,prices,dp));
        }
        
        return dp[ind][buy][c] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,prices,dp);    
    }
};