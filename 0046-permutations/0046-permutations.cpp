class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&temp,vector<int>&freq,vector<int>& nums)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                temp.push_back(nums[i]);
                freq[i]=1;
                f(temp,freq,nums);
                freq[i]=0;
                temp.pop_back();
                
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int>temp;
        int n=nums.size();
        vector<int>freq(n,0);
        f(temp,freq,nums);
        return ans;
    }
};