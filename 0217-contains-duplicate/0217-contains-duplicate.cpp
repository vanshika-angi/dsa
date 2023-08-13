class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //2 for loops and check for repition
        //one for loop and one map to store freq
        
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)return true;
        }
        return false;
    }
};