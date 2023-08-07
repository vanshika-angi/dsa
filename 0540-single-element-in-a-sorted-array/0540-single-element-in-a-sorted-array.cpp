class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int n=nums.size();
        
        int low=0;
        int high=n-1;
        if(n==1 || nums[0]!=nums[1] )return nums[0];
        if(nums[n-2]!=nums[n-1])return nums[n-1];
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            // cout<<mid<<endl;
            if(mid>0 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            
            if(nums[mid-1]==nums[mid] )
            {
                if(mid%2==1)low=mid+1;
                else high=mid;
            }
            else if(nums[mid+1] == nums[mid])
            {
                if(mid%2==0)low=mid;
                else high=mid-1;
            }
        }
        
        return -1;
    }
};