class Solution {
public:
    vector<vector<int>>ans;
    void f(int ind, vector<int>&temp,vector<int>&nums,int n)
    {
        //base case
        
            ans.push_back(temp);
            
        
        for(int i=ind;i<n;i++)
        {
            if(i>ind && nums[i]==nums[i-1])continue;
            
            temp.push_back(nums[i]);
            f(i+1,temp,nums,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<int>temp;
        int n=nums.size();
        f(0,temp,nums,n);
        return ans;
    }
};