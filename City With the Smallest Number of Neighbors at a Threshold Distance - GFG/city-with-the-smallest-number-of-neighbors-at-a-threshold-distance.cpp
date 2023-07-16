//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     vector<vector<int>>matrix(n, vector<int>(n,1e9));
                     for(int i=0;i<n;i++)
                     {
                         for(int j=0;j<n;j++)
                         {
                             if(i==j)matrix[i][j]=0;
                         }
                     }
                     
                     for(auto it:edges)
                     {
                         int u=it[0];
                         int v=it[1];
                         int wt=it[2];
                         
                         matrix[u][v]=wt;
                         matrix[v][u]=wt;
                     }
                     
                     for(int k=0;k<n;k++)
                     {
                         for(int i=0;i<n;i++)
                         {
                             for(int j=0;j<n;j++)
                             {
                                 matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                             }
                         }
                     }
                     
                     vector<int>count(n,0);
                     int ans=INT_MAX,city=-1;
                     for(int i=0;i<n;i++)
                     {
                         int temp=0;
                         for(int j=0;j<n;j++)
                         {
                             if(matrix[i][j]<=distanceThreshold)temp++;
                         }
                         count[i]=temp;
                         if(temp<=ans)
                         {
                             ans=temp;
                             city=i;
                         }
                     }
                     return city;
                     
                     
                     
                     
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends