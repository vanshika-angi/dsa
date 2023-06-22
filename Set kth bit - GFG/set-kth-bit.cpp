//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setKthBit(int N, int K)
    {
        int temp=1;
        temp=temp<<(K);
        // cout<<temp<<endl;
        return N|temp;
        // Write Your Code here
    }
    
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        
        Solution ob;
        int ans = ob.setKthBit(N,K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends