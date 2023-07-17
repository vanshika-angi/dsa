class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end());
        vector<vector<int>>ans;
        ans.push_back(interval[0]);
        int n=interval.size();
        int k=0;
        
        for(int i=1;i<n;i++)
        {
            if(interval[i][0]<=ans[k][1] && interval[i][0]>=ans[k][0])
            {
                int mini=min(ans[k][0],interval[i][0]);
                int maxi=max(ans[k][1],interval[i][1]);
                ans[k][0]=mini;
                ans[k][1]=maxi;
            }
            else
            {
                ans.push_back(interval[i]);
                k++;
            }
        }
        return ans;
    }
};