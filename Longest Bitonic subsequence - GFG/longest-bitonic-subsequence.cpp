//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    int n=arr.size();
	    vector<int>dp_inc(n,1), dp_dec(n,1);
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i-1;j>=0;j--)
	        {
	            if(arr[j]<arr[i] && dp_inc[i]<dp_inc[j]+1)
	            {
	                dp_inc[i]=dp_inc[j]+1;
	            }
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(arr[i]>arr[j] && dp_dec[i]<dp_dec[j]+1)
	            {
	                dp_dec[i]=dp_dec[j]+1;
	            }
	        }
	    }
	    int maxi=1;
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,dp_inc[i]+dp_dec[i]);
	    }
	    
	    return maxi-1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends