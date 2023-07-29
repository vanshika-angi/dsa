class Solution {
public:
    vector<vector<int>>ans;
    // vector<int>nums{1,2,3,4,5,6,7,8,9};
    void f(int i,int sum,vector<int>&temp, int k,int target)
    {
        //base case
        if(k==0)
        {
            if(sum==target)ans.push_back(temp);
            return;
        }
        if(i>=10)return;
        //include
        if(sum+i<=target)
        {
            temp.push_back(i);
            f(i+1,sum+i,temp,k-1,target);
            temp.pop_back();
         
        }
        
        //not include
        f(i+1,sum,temp,k,target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int>temp;
        f(1,0,temp,k,n);
        return ans;
        
    }
};