//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    // int helper_memo(int ind,int len,int price[],vector<vector<int>>&dp)
    // {
    //     if(ind==0)
    //     {
    //         return  len*price[0];
    //     }
    //     if(dp[ind][len]!=-1)return dp[ind][len];
    //     int notcut= 0 +helper(ind-1,len,price,dp);
    //     int cut=0;
    //     int rod=ind+1;
    //     if(len-rod>=0)cut = price[ind] + helper(ind,len-rod,price,dp);
        
    //     return dp[ind][len] = max(notcut,cut);
    // }
    
    
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        // return helper_tab(n-1,n,price,dp);
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=i*price[0];
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int len=0;len<=n;len++)
            {
                int notcut= dp[ind-1][len];
                int cut=0;
                int rod=ind+1;
                if(len-rod>=0)cut = price[ind] + dp[ind][len-rod];
                
                dp[ind][len] = max(notcut,cut);
            }
        }
        
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends