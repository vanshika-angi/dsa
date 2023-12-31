//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int>ans;
    void f(int i,int sum,vector<int>arr,int n)
    {
        if(i==n)
        {
            ans.push_back(sum);
            return;
        }
        
        //include
        f(i+1,sum+arr[i],arr,n);
        
        //not include
        f(i+1,sum,arr,n);
        
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
       f(0,0,arr,n);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends