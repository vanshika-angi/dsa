class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap=k;
       for(int i=0;i<k && i<nums.size();i++)
       {
           pq.push(nums[i]);
       }
        
        for(int i=k;i<nums.size();i++)
        {
            if(!pq.empty() && nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()<cap)pq.push(val);
        else if(!pq.empty() && (val>pq.top()))
        {
            pq.pop();
            pq.push(val);
        }
        
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */