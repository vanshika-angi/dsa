class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=0,fast=0;
        int flag=1;
        while(flag==1 || slow!=fast)
        {
            // cout<<slow<<" "<<fast<<endl;
            slow=nums[slow];
            fast=nums[nums[fast]];
            flag=0;
        }
        fast=0;
        while(fast!=slow)
        {
            fast=nums[fast];
            slow=nums[slow];
            // cout<<slow<<" "<<fast<<endl;
            if(fast==slow)
            {
                return slow;
            }
        }
        return slow;
    }
};