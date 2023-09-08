class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxI=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i<=maxI)
            {
              maxI = max(maxI, i + nums[i]);  
            }
            
        }
        if(maxI>=n-1)return true;
        return false;
    }
};