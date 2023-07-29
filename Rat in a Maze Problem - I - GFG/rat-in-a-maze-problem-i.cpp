//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    map<char,pair<int,int>>dir;
    void solve(int row,int col,string path,vector<vector<int>> &m, int n,vector<vector<int>>&vis)
    {
        if(m[row][col]==0)return;
        //base case
        if(row==n-1 && col==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        
        //recursion
        vis[row][col]=1;
        for(auto x:dir)
        {
            int newrow = row+x.second.first;
            int newcol = col+x.second.second;
            
            if(newrow>=0 && newcol>=0 && newrow<n && newcol<n && 
            vis[newrow][newcol]==0 && m[newrow][newcol]==1)
            {
                path+=x.first;
                solve(newrow,newcol,path,m,n,vis);
                path.pop_back();
            }
        }
        
        vis[row][col]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
       string path;
       dir['U']={-1,0};
       dir['R']={0,1};
       dir['D']={1,0};
       dir['L']={0,-1};
       vector<vector<int>>vis(n,vector<int>(n,0));
       solve(0,0,path,m,n,vis);
    //   cout<<"size"<<ans.size();
       if(ans.size()==0)
       {
           
           ans.push_back({"-1"});
            // cout<<"size"<<ans.size();
       }
       return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends