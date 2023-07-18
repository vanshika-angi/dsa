class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int ans=0;
        int n=nums.size();
       int expected=(n*(n+1))/2;

       for(int i=0;i<n;i++)
       {
           ans+=nums[i];
       }
        return expected-ans;
    }
};