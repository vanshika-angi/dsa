class Solution {
public:
    vector<vector<int>>ans;
    
    void f(int i,int sum,vector<int>&temp,int n,vector<int>& candidates, int target)
    {
        //base case
        if(sum>target)return;
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(i>=n)return;
        
        
        //include
        temp.push_back(candidates[i]);
        f(i,sum+candidates[i],temp,n,candidates,target);
        
        //notinclude
        temp.pop_back();
        f(i+1,sum,temp,n,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int>temp;
        int n=candidates.size();
        f(0,0,temp,n,candidates,target);
        return ans;
    }
};