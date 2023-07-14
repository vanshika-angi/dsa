class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        int m=prerequisites.size();
        for(int i=0;i<m;i++)
        {
            cout<<i<<endl;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        
        if (topo.size()==n)return true;
        return false;
    }
};