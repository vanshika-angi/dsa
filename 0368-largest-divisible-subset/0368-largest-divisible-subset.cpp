class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int maxi=1;
        int lastindex=0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    // cout<<nums[i]<<endl;
                    dp[i]=dp[j]+1;
                    // cout<<dp[i];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                cout<<maxi<<endl;
                lastindex=i;
            }
        }
        vector<int>ans;
        while(hash[lastindex]!=lastindex)
        {
            ans.push_back(nums[lastindex]);
            lastindex=hash[lastindex];
        }
        
        ans.push_back(nums[lastindex]);
        return ans;
        
    }
};