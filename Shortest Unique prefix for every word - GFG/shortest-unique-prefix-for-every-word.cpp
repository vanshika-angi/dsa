//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class TrieNode
{
    public:
    TrieNode* child[26];
    bool isEnd;
    int count;
    
    TrieNode()
    {
        isEnd=false;
        count=0;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};

class Solution
{
    public:
    vector<string>res;
    void insertTrie(TrieNode*root, string key)
    {
       TrieNode*curr=root;
    //   cout<<key<<endl;
       for(int i=0;i<key.length();i++)
       {
            
           int index=key[i]-'a';
           if(curr->child[index]==NULL)
           {
               curr->child[index]=new TrieNode();
              curr->count=curr->count+1;
                // cout<<key[i]<<" - "<<curr->child[index]->count<<endl;
           }
           curr=curr->child[index];
       }
       curr->isEnd=true;
    }
    string findPrefix(TrieNode*root, string key)
    {
        TrieNode*curr=root;
        // for(int i=0;i<26;i++)
        // {
        //     cout<<curr->child[i]<<" "<<i<<endl;
        // }
        // int index=key[0]-'a';
        // cout<<index<<endl;
        // curr=curr->child[index];
        
        bool flag=false;
        int idx=-1;
        for(int i=0;i<key.length();i++) /// ROOT. [[Z]]EBRA
        { //i=1
            int index=key[i]-'a'; //4
            curr=curr->child[index]; //E
            if((curr->count==1 || curr->count==0 )&& flag==false)
            {
               flag=true;
               idx=i;
            }
            else if(curr->count>1)
            {
                flag=false;
                idx=-1;
            }
            
            
        }
        // cout<<key<<" - "<<idx<<endl;
        return key.substr(0,idx+1);
        // return "";
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        TrieNode*root=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            insertTrie(root,arr[i]);
        }
        for(int i=0;i<n;i++)
        {
           string ans = findPrefix(root,arr[i]); 
           res.push_back(ans);
        }
        return res;
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

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends