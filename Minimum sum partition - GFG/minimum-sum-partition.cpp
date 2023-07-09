//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int target=0;
	    for(int i=0;i<n;i++)
	    {
	        target+=arr[i];
	    }
	    
	    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
	    
	    for(int i=0;i<n;i++)
	    {
	        dp[i][0]=true;
	    }
	    
	    if(arr[0]<=target)dp[0][arr[0]]=true;
	    
	    
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<=target;j++)
	        {
	            dp[i][j]=dp[i-1][j];
	            if(j-arr[i]>=0)dp[i][j] = dp[i][j] || dp[i-1][j-arr[i]];
	        }
	    }
	    int ans=INT_MAX;
	    for(int j=0;j<=target;j++)
	    {
	       if(dp[n-1][j])
	       {
	           int sum1=j;
	           int sum2=target-j;
	           ans=min(ans,abs(sum1-sum2));
	           
	       }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends