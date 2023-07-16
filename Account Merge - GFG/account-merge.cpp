//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet{
    vector<int>parent,size;
    
public:

    DisjointSet(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findParent(int node)
    {
        if(node==parent[node])return node;
        else return parent[node] = findParent(parent[node]);
    }
    

    
    void unionBySize(int u,int v)
    {
        int upu=findParent(u);
        int upv=findParent(v);
        if(upu==upv)return;
        
        if(size[upu]<size[upv])
        {
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else 
        {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        
    }
    
};


class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end())
                {
                    mp[mail]=i;
                }
                else{
                   ds.unionBySize(i,mp[mail]); 
                }
            }
        }
        
        vector<string> mergeMail[n];
        for(auto it:mp)
        {
            string mail=it.first;
            int node=ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        
        }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(mergeMail[i].size()==0)continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
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
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends