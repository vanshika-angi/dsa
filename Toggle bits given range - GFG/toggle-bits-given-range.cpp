//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        // code here
        int count=R-L;
        int temp=1;
        while(count)
        {
            temp=temp<<1;
            temp=temp+1;
            count--;
        }
        temp=temp<<(L-1);
        int ans=N^temp;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends