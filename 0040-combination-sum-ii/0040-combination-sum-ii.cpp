class Solution {
public:
    vector<vector<int>>ans;
    
    void f(int i,int sum,vector<int>&temp,int n,vector<int>&nums,int target)
    {
        //base case
        
       if(sum==target)
        {
            ans.push_back(temp);
           return;
        } 
            
        
        //include
        for(int ind=i;ind<n;ind++)
        {
            if(ind>i && nums[ind]==nums[ind-1])continue;
            if(sum+nums[i]>target)break;
            
            temp.push_back(nums[ind]);
            f(ind+1,sum+nums[ind],temp,n,nums,target);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
      vector<int>temp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        f(0,0,temp,n,nums,target);
        return ans;

    }
};