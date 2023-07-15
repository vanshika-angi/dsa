//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
       if(grid[destination.first][destination.second]==0)return -1;                  
       int n=grid.size();
       int m=grid[0].size();
       set<pair<int,pair<int,int>>>st;
       vector<vector<int>>dist(n,vector<int>(m,1e9));
       vector<int>delrow{-1,0,1,0};
       vector<int>delcol{0,1,0,-1};
       
       st.insert({0,source});
       dist[source.first][source.second]=0;
       
       while(!st.empty())
       {
           auto it=*(st.begin());
           int step=it.first;
           int row=it.second.first;
           int col=it.second.second;
           st.erase(it);
        //   cout<<step<<" "<<row<<" "<<col<<endl;
           
           for(int i=0;i<4;i++)
           {
               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               if(nrow>=0 && ncol>=0 && nrow<n && ncol<m
                && grid[nrow][ncol]==1)
                {
                    
                    if(step+1<dist[nrow][ncol])
                    {
                        
                        if(dist[nrow][ncol]!=1e9)
                        {
                            st.erase({dist[nrow][ncol],{nrow,ncol}});
                        }
                        
                        dist[nrow][ncol]=step+1;
                        st.insert({step+1,{nrow,ncol}});
                        // cout<<dist[nrow][ncol]<<endl;
                    }
                }
           }
       }
       
       if(dist[destination.first][destination.second]==1e9)return -1;
        return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends