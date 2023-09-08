class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int num=0,j=0,ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if((num&nums[i])!=0)
            {
                while((num&nums[i])!=0)
                {
                    num ^= nums[j];
                    j++;
                }
            }
            
            num=num|nums[i];
            ans=max(ans,i-j+1);
        }
        
        return ans;
    }
};