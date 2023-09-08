class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,current=0,farthest=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            farthest = max(farthest,nums[i]+i);
            if(i==current)
            {
                if(i==n-1)return jumps;
                current = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};