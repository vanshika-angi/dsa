class Solution {
public:
    // int helper(int i,int j,string word1,string word2,vector<vector<int>>&dp)
    // {
    //     if(i<0 && j>=0)return j+1;
    //     if(j<0 && i>=0)return i+1;
    //     if(i<0 && j< 0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(word1[i]==word2[j])
    //     {
    //         return dp[i][j] = helper(i-1,j-1,word1,word2,dp);
    //     }
    //     else
    //     {
    //         return dp[i][j] = 1+min(helper(i-1,j-1,word1,word2,dp),min(helper(i-1,j,word1,word2,dp),helper(i,j-1,word1,word2,dp)));
    //     }
    // }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
             if(word1[i-1]==word2[j-1])dp[i][j] = dp[i-1][j-1];
        
             else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])); 
            }
        }

        return dp[n][m];
        // return helper(n-1,m-1,word1,word2,dp);
    }
};