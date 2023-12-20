class Solution {
public:
    int check(vector<int>& weights, int mid)
    {
        int n=weights.size();
        int sum=0;
        int days=1;
        for(int i=0;i<n;i++)
        {
            if(weights[i]>mid)return INT_MAX;
            sum+=weights[i];
            if(sum<=mid)
            {
                continue;
            }
            else
            {
                days++;
                sum=weights[i];
            }
        }
        // if(sum!=0)days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
        }
        int low=1,high=sum;
        int ans=sum;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            int temp = check(weights,mid);
            if(temp==INT_MAX)low=mid+1;
            if(temp>days)
            {
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
            
        }
        return ans;
        
    }
};