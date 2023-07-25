class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        priority_queue<pair<int,int>>pq;
        for(auto x:mp)pq.push({x.second,x.first});
        vector<int>ans;
        while(k--)
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
            
        }
        
        return ans;
    }
};