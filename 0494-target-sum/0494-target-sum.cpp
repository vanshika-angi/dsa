class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int add=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            add=add+arr[i];
        }
        if(add<target || (add+target)%2==1 || add+target<0)return 0;
        int sum=(target+add)/2;
        // if(sum%2==1)return 0;
        
         int dp[n+1][sum+1];
        
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(arr[i-1]<=j )
                {
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=sum;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n][sum];
    }
};