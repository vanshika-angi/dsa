class Solution {
public:
    bool check(vector<int>& nums) {
       int count=1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])continue;
            else
            {
                if(count)count--;
                else return false;
                    
            }
        }
        
        if(nums[0]<nums[n-1] && count==0)return false;
        return true;
    }
};