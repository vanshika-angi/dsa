//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool possible(int node,int col,vector<int>&color,bool graph[101][101],int n)
    {
        for(int i=0;i<=node;i++)
        {
            if(graph[node][i])
            {
                if(color[i]==col)return false;
            }
        }
        return true;
    }
    
    
    bool solve(int node, vector<int>&color,bool graph[101][101],int m,int n)
    {
        //base case
        if(node==n)return true;
        
        //recursion
        for(int col=1;col<=m;col++)
        {
            if(possible(node,col,color,graph,n)==true)
            {
                color[node]=col;
                if(solve(node+1,color,graph,m,n)==true)return true;
                
                //backtrack
                else
                color[node]==0;
            }
            
        }
        
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
            if(color[i]==0)
            {
                if(solve(i,color,graph,m,n)==false)return false;
            }
        }
        return true;
     
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends