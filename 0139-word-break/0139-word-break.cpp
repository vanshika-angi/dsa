class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(auto x:wordDict)
        {
            mp[x]++;
        }
        
        int n=s.length();
        vector<bool>dp(n,false);
        
        for(int i=0;i<n;i++)
        {
            string temp=s.substr(0,i+1);

            if(mp.find(temp)!=mp.end())
            {
                // cout<<i<<endl;
                // cout<<temp<<endl;
                dp[i]=true;   
            }

            for(int j=0;j<i;j++)
                {
                    if(dp[j])
                    {
                        int len=i-j;
                        string temp2=s.substr(j+1,len);
                        if(mp.find(temp2)!=mp.end())
                        {
                            
                            // cout<<j+1<<" "<<len<<endl;
                            cout<<temp2<<endl;
                            dp[i]=true;
                        }
                        
                    }
                }
        }
        
        return dp[n-1];
    }
};