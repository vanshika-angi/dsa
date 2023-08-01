class Solution {
public:
    // int helper(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>&dp)
    // {
    //     if(cap==0)return 0;
    //     if(ind==prices.size())return 0;
        
    //     if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];

    //     int profit=0;
    //     if(buy)
    //     {
    //         profit=max(-prices[ind]+helper(ind+1,0,cap,prices,dp), helper(ind+1,1,cap,prices,dp));
    //     }
    //     else
    //     {
    //         profit= max(prices[ind]+helper(ind+1,1,cap-1,prices,dp),helper(ind+1,0,cap,prices,dp));
    //     }
    //     return dp[ind][buy][cap] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>>dp(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        
            // for(int buy=0;buy<=1;buy++)
            // {
            //     dp[buy][0]=0;
            // }
        

        // for(int buy=0;buy<=1;buy++)
        // {
        //     for(int cap=0;cap<3;cap++)
        //     {
        //         dp[buy][cap]=0;
        //     }
        // }

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=2;cap>=1;cap--)
                {
                  int profit=0;
                    if(buy)
                    {
                        profit=max(-prices[ind]+dp[0][cap], dp[1][cap]);
                    }
                    else
                    {
                        profit= max(prices[ind]+dp[1][cap-1],dp[0][cap]);
                    }
                    curr[buy][cap] = profit;  
                }
            }
            dp=curr;
        }
        return dp[1][2];

        // return helper(0,1,2,prices,dp);
    }
};