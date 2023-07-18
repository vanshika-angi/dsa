class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int e=0,o=n/2;
        vector<int>temp(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                temp[o]=nums[i];
                o++;
            }
            else
            {
                temp[e]=nums[i];
                e++;
            }
        }
        e=0;
        o=n/2;
        vector<int>ans;
        int i=0;
        while(i<n-1)
        {
            nums[i] = (temp[e]);
            nums[i+1] = (temp[o]);
            e++;
            o++; 
            i=i+2;
        }
        return nums;
    }
};