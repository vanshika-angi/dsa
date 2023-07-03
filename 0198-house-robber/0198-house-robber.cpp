class Solution {
public:
    int rob(vector<int>& nums) {
      
        int n=nums.size();
        if(nums.size()==1)return nums[0];
        vector<int>dp(n+1,0);
        vector<int>maxi(n+1,0);
        
        dp[1]=nums[0];
        dp[2]=nums[1];
        maxi[1]=nums[0];
        maxi[2]=max(nums[0],nums[1]);
        int maxVal=max(maxi[1],maxi[2]);
        for(int i=3;i<=n;i++)
        {
            // cout<<nums[i-1]<<endl;
            dp[i]=maxi[i-2]+nums[i-1];
            maxVal=max(maxVal,dp[i]);
            maxi[i]=maxVal;
            
        }
        
        return maxVal;
    }
};