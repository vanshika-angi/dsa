//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         int n=intervals.size();
         sort(intervals.begin(), intervals.end());
        for(int i=1;i<n;i++){
            int l=intervals[i-1][0];
            int r=intervals[i-1][1];
            //inside check
            if(intervals[i][0]>=l && intervals[i][0]<=r){
            l=min(l,intervals[i][0]);
            r=max(r,intervals[i][1]);
            intervals.erase(intervals.begin()+i);
            intervals[i-1][0]=l;
            intervals[i-1][1]=r;
            n--;
            i--;
            }
            }
            return intervals;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends