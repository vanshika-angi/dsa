//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // vector<pair<int,int>>adj[n];
        // for(auto it:roads)
        // {
        //     adj[it[0]].push_back({it[1],it[2]});
        //     adj[it[1]].push_back({it[0],it[2]});
        // }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // vector<int>dist(n,INT_MAX);
        // vector<int>count(n,0);
        // int dest=n-1;
        // dist[0]=0;
        // count[0]=1;
        // pq.push({0,0});
        // int mod=(int)(1e9+7);
        
        // while(!pq.empty())
        // {
        //     int time=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();
        //     // if(node==dest)continue;
        //     for(auto it:adj[node])
        //     {
        //         int adjnode=it.first;
        //         int weight=it.second;
                
        //         int temp=time+weight;
        //         if(temp<dist[adjnode])
        //         {
        //             dist[adjnode]=temp;
        //             count[adjnode]=count[node];
        //             pq.push({temp,adjnode});
        //         }
        //         else if(temp==dist[adjnode])
        //         {
        //             count[adjnode]=(count[adjnode]+count[node])%mod;
        //             // pq.push({temp,adjnode});
        //         }
        //     }
        // }
        
        // return count[n-1]%mod;
        
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap). 
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initializing the dist array and the ways array
        // along with their first indices.
        vector<double> dist(n, INT_MAX); 
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        int mod = (int)(1e9 + 7);

        // Iterate through the graph with the help of priority queue
        // just as we do in Dijkstra's Algorithm.
        while (!pq.empty())
        {
            double dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                // cout<<"Node:"<<adjNode<<"Sum dist"<<dis + edW<<endl;
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }

                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
                
                // if(adjNode==5)
                // {
                //     cout<<node<<" "<<ways[adjNode]<<endl;
                // }
            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends