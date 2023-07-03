class Solution {
public:
    bool canJump(vector<int>& nums) {
     int maxidx=0;

     for(int i=0;i<=maxidx;i++)
     {
         maxidx=max(i+nums[i],maxidx);
        //  cout<<nums[i]<<" "<<maxidx<<endl;
         if(maxidx>=nums.size()-1)
         {
             return true;
         }
     }   

     return false;
    }
};