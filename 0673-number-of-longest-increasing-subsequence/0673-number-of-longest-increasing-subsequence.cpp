class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1),count(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        maxi=max(maxi,dp[i]);
                        count[i]=count[j];
                    }
                    else if(dp[i]==dp[j]+1)
                    {
                        count[i]=count[i]+count[j];
                    }
                }
            }
        }
        int ans=0;
        // cout<<maxi<<endl;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                ans+=count[i];
            }
        }

        return ans;
    }
};